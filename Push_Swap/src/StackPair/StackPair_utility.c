#include "StackPair.h"
#include "IntStack.h"

static IntStack *get_stack(StackPair *sp, e_StackSide side)
{
    if (side == A_STACK)
        return sp->stack_a;
    return sp->stack_b;
}

int         stackPairPeek(StackPair *sp, e_StackSide side, int *res)
{
    return intStackPeek(get_stack(sp, side), res);
}

int         stackPairPeekFew(StackPair *sp, e_StackSide side, int *buffer, int n)
{
    return intStackPeekFew(get_stack(sp, side), buffer, n);
}

int         stackPairSwap(StackPair *sp, e_StackSide side)
{
    int res;

    if (side == A_STACK)
        res = sa_cmd(sp);
    else
        res = sb_cmd(sp);
    return (res);
}

int         stackPairCheckOrder(StackPair *sp, e_StackSide side, int n)
{
    int ascending;

    if (side == A_STACK)
        ascending = 1;
    else
        ascending = 0;
    return intStackCheckOrder(get_stack(sp, side), n, ascending);
}

