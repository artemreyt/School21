#include "StackPair.h"
#include "IntStack.h"

void    rra_cmd(StackPair *sp)
{
    if (intStackShiftDown(sp->stack_a))
        stackPairLog(sp, RRA_MSG);
}

void    rrb_cmd(StackPair *sp)
{
    if (intStackShiftDown(sp->stack_b))
        stackPairLog(sp, RRB_MSG);
}
void    rrr_cmd(StackPair *sp)
{
    if (intStackShiftDown(sp->stack_a) || intStackShiftDown(sp->stack_b))
        stackPairLog(sp, RRR_MSG);
}
