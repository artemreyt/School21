#include "Push_Swap.h"
#include "StackPair.h"
#include <stdlib.h>

void    push_swap_sort(StackPair *sp, int *arr, t_ChunkInfo *chunk_info)
{
    int buffer[2];
    int i;

    if (!chunk_info->length && chunk_info->length > 2)
        exit(EXIT_FAILURE);
    if (chunk_info->length == 2)
    {
        if (!stackPairPeekFew(sp, chunk_info->side, buffer, 2))
            exit(EXIT_FAILURE);
        if ((chunk_info->side == A_STACK && buffer[0] > buffer[1]) ||
                (chunk_info->side == B_STACK && buffer[0] < buffer[1]))
        {
            if (!stackPairSwap(sp, chunk_info->side))
                exit(EXIT_FAILURE);
        }
    }
    if (chunk_info->side == B_STACK)
    {
        i = 0;
        while (i++ < chunk_info->length)
            pa_cmd(sp);
    }
}
