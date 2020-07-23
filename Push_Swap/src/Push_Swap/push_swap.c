#include "push_swap.h"
#include "stack_pair.h"
#include "ft_algorithms.h"
#include "libft.h"
#include <unistd.h>

void        launch_push_swap(int *arr, int n)
{
    t_stack_pair   *sp;
    t_chunk_info chunkInfo;

    sp = stack_pair_сreate(arr, n, STDOUT_FILENO);
    radix_sort(arr, n);
    chunkInfo.start_index = 0;
    chunkInfo.length = n;
    chunkInfo.side = A_STACK;
    push_swap(sp, arr, &chunkInfo);
    stack_pair_free(&sp);
}

static void init_chunks(t_chunk_info *current, t_chunk_info *left, t_chunk_info *right)
{
    right->start_index = current->start_index + current->length / 2;
    right->length = current->start_index + current->length - right->start_index;
    right->side = A_STACK;
    left->start_index = current->start_index;
    left->length = current->length - right->length;
    left->side = B_STACK;
}

static void push_swap_move_chunk(t_stack_pair *sp, t_chunk_info *chunk)
{
    int     i;

    if (chunk->side == A_STACK)
        return ;
    i = 0;
    while (i < chunk->length)
    {
        pa_cmd(sp);
        ++i;
    }
}

void        push_swap(t_stack_pair *sp, int *arr, t_chunk_info *chunk)
{
    t_chunk_info left_chunk;
    t_chunk_info right_chunk;
    int         res;

    res = stack_pair_check_order(sp, chunk->side, chunk->length);
    if (res > 0)
    {
        push_swap_move_chunk(sp, chunk);
        return ;
    }
    else if (res < 0)
        exit(EXIT_FAILURE);
    if (chunk->length <= 2)
        push_swap_sort(sp, chunk);
    else
    {
        push_swap_partition(sp, arr, chunk);
        init_chunks(chunk, &left_chunk, &right_chunk);
        push_swap(sp, arr, &right_chunk);
        push_swap(sp, arr, &left_chunk);
    }
}
