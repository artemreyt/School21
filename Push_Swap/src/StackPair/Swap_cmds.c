#include "StackPair.h"
#include "IntStack.h"

void    sa_cmd(StackPair *sp)
{
    if (intStackSwap(sp->stack_a))
        stackPairLog(sp, SA_MSG);
}

void    sb_cmd(StackPair *sp)
{
    if (intStackSwap(sp->stack_a))
        stackPairLog(sp, SB_MSG);
}

void    ss_cmd(StackPair *sp)
{
    if (intStackSwap(sp->stack_a) || intStackSwap(sp->stack_b))
        stackPairLog(sp, SS_MSG);
}
