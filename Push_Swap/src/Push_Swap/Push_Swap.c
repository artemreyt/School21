#include "Push_Swap.h"
#include "StackPair.h"
#include "ft_algorithms.h"
#include <unistd.h>

void        launch_push_swap(int *arr, int n)
{
    StackPair   *sp;
    t_ChunkInfo chunkInfo;

    sp = stackPairCreate(arr, n, STDOUT_FILENO);
    radix_sort(arr, n);
    chunkInfo.start_index = 0;
    chunkInfo.length = n;
    chunkInfo.side = A_STACK;
    push_swap(sp, arr, &chunkInfo);
}

static void init_chunks(t_ChunkInfo *current, t_ChunkInfo *left, t_ChunkInfo *right)
{
    right->start_index = current->start_index + current->length / 2;
    right->length = (current->length + 1) / 2;
    right->side = B_STACK;
    left->start_index = current->start_index;
    left->length = current->length - right->length;
    left->side = A_STACK;
}

void        push_swap(StackPair *sp, int *arr, t_ChunkInfo *chunk)
{
    t_ChunkInfo left_chunk;
    t_ChunkInfo right_chunk;

    if (chunk->length <= 2)
        push_swap_sort(sp, arr, chunk);
    else
    {
        push_swap_partition(sp, arr, chunk);
        init_chunks(chunk, &left_chunk, &right_chunk);
        push_swap(sp, arr, &right_chunk);
        push_swap(sp, arr, &left_chunk);
    }
}
