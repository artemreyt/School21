#include "push_swap.h"
#include "stack_pair.h"
#include <stdlib.h>

void    push_swap_sort(t_stack_pair *sp, t_chunk_info *chunk_info)
{
    int buffer[2];
    int i;

    if (!chunk_info->length && chunk_info->length > 2)
        exit(EXIT_FAILURE);
    if (chunk_info->length == 2)
    {
        if (!stack_pair_peek_few(sp, chunk_info->side, buffer, 2))
            exit(EXIT_FAILURE);
        if ((chunk_info->side == A_STACK && buffer[0] > buffer[1]) ||
                (chunk_info->side == B_STACK && buffer[0] < buffer[1]))
        {
            if (!stack_pair_swap(sp, chunk_info->side))
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
