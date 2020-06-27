#include "Push_Swap.h"
#include "StackPair.h"
#include "IntStack.h"

inline static int   greather_or_equal(int a, int b)
{
    return a >= b;
}

inline static int   lower_or_equal(int a, int b)
{
    return a <= b;
}

void                push_swap_partition(StackPair *sp, int *arr, t_ChunkInfo *chunk_info)
{
    int     i;
    int     (*comparator)(int, int);
    int     (*getter)(StackPair *, int *);
    void    (*rotater)(StackPair *);
    void    (*pusher)(StackPair *);

//    pivot = arr[chunk_info->start_index + chunk_info->length / 2];
    comparator = chunk_info->side == A_STACK ? lower_or_equal : greather_or_equal;
    pusher = chunk_info->side == A_STACK ? pb_cmd : pa_cmd;
    getter = chunk_info->side == A_STACK ? stackPairPeek_a : stackPairPeek_b;
    rotater = chunk_info->side == A_STACK ? ra_cmd : rb_cmd;
    i = 0;
    while (i < chunk_info->length)
    {
        if (comparator(arr[chunk_info->start_index + chunk_info->length / 2], getter(sp, )))
    }

}
