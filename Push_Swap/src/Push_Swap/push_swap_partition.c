#include "push_swap.h"
#include "stack_pair.h"
#include "int_stack.h"
#include <stdlib.h>
#include "ft_printf.h"

static int  get_number(t_stack_pair *sp, t_stack_side side)
{
    int     number;

    if (!stack_pair_peek(sp, side, &number))
        exit(EXIT_FAILURE);
    return number;
}

static int  compare(int number, int pivot, t_stack_side side)
{
    if (side == A_STACK)
        return number < pivot;
    return number >= pivot;
}

static void rotate(t_stack_pair *sp, t_stack_side side, int num)
{
    void    (*rotator)(t_stack_pair *);

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

static void push(t_stack_pair *sp, t_stack_side side)
{
    if (side == A_STACK)
        pb_cmd(sp);
    else
        pa_cmd(sp);
}

void        push_swap_partition(t_stack_pair *sp, const int *arr, t_chunk_info *chunk_info)
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
