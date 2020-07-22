#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "StackPair.h"

struct  s_ChunkInfo
{
    e_StackSide side;
    int         start_index;
    int         length;
};
typedef struct s_ChunkInfo  t_ChunkInfo;

void    launch_push_swap(int *arr, int n);
void    push_swap(StackPair *sp, int *arr, t_ChunkInfo *chunk_info);
void    push_swap_partition(StackPair *sp, const int *arr, t_ChunkInfo *chunk_info);
void    push_swap_sort(StackPair *sp, t_ChunkInfo *chunk_info);

/*
 * optimization part
 */
//void    push_swap_move_chunk(StackPair *sp, t_ChunkInfo *chunk);


#endif
