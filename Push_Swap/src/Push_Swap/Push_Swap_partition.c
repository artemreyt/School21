#include "Push_Swap.h"
#include "StackPair.h"
#include "IntStack.h"
#include <stdlib.h>
#include "ft_printf.h"

static int  get_number(StackPair *sp, e_StackSide side)
{
    int     number;

    if (!stackPairPeek(sp, side, &number))
        exit(EXIT_FAILURE);
    return number;
}

static int  compare(int number, int pivot, e_StackSide side)
{
    if (side == A_STACK)
        return number < pivot;
    return number >= pivot;
}

static void rotate(StackPair *sp, e_StackSide side, int num)
{
    void    (*rotator)(StackPair *);

    if (num > 0)
    {
        if (side == A_STACK)
            rotator = ra_cmd;
        else
            rotator = rb_cmd;
    }
    else
    {
        if (side == A_STACK)
            rotator = rra_cmd;
        else
            rotator = rrb_cmd;
    }
    num = num < 0 ? -num : num;
    while (num)
    {
        rotator(sp);
        --num;
    }
}

static void push(StackPair *sp, e_StackSide side)
{
    if (side == A_STACK)
        pb_cmd(sp);
    else
        pa_cmd(sp);
}

void        push_swap_partition(StackPair *sp, const int *arr, t_ChunkInfo *chunk_info)
{
    int rotate_num;
    int number;
    int pivot;
    int need_to_push;
    int stack_len;

    stack_len = chunk_info->side == A_STACK ? sp->stack_a->size : sp->stack_b->size;
    pivot = arr[chunk_info->start_index + chunk_info->length / 2];
    rotate_num = 0;
    if (chunk_info->side == A_STACK)
        need_to_push = chunk_info->length / 2;
    else
        need_to_push = chunk_info->length - chunk_info->length / 2;
    while (need_to_push > 0)
    {
        number = get_number(sp, chunk_info->side);
        if (compare(number, pivot, chunk_info->side))
        {
            push(sp, chunk_info->side);
            --need_to_push;
        }
        else
        {
            rotate(sp, chunk_info->side, +1);
            ++rotate_num;
        }
    }
    if (chunk_info->length < stack_len)
        rotate(sp, chunk_info->side, -rotate_num);
}
