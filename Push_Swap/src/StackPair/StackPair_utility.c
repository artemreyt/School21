#include "StackPair.h"

int         stackPairPeek_a(StackPair *sp, int *res)
{
    return intStackPeek(sp->stack_a, res);
}

int         stackPairPeek_b(StackPair *sp, int *res)
{
    return intStackPeek(sp->stack_b, res);
}
