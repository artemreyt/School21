#include "StackPair.h"
#include "IntStack.h"

int    sa_cmd(StackPair *sp)
{
    int res;

    res = intStackSwap(sp->stack_a);
    if (res)
        stackPairLog(sp, SB_MSG);
    return (res);
}

int    sb_cmd(StackPair *sp)
{
    int res;

    res = intStackSwap(sp->stack_b);
    if (res)
        stackPairLog(sp, SB_MSG);
    return (res);
}

int    ss_cmd(StackPair *sp)
{
    if (intStackSwap(sp->stack_a) || intStackSwap(sp->stack_b))
    {
        stackPairLog(sp, SS_MSG);
        return (1);
    }
    return (0);
}
