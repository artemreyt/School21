#include "Push_Swap.h"
#include "StackPair.h"
#include "IntStack.h"
#include <stdlib.h>

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
        return number <= pivot;
    return number >= pivot;
}

static void rotate(StackPair *sp, e_StackSide side)
{
    if (side == A_STACK)
        ra_cmd(sp);
    else
        rb_cmd(sp);
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
    int i;
    int number;
    int pivot;

    pivot = arr[chunk_info->start_index + chunk_info->length / 2];
    i = 0;
    while (i < chunk_info->length)
    {
        number = get_number(sp, chunk_info->side);
        if (compare(number, pivot, chunk_info->side))
            push(sp, chunk_info->side);
        rotate(sp, chunk_info->side);
        ++i;
    }
}
