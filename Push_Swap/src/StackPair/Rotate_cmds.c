#include "StackPair.h"
#include "IntStack.h"

void    ra_cmd(StackPair *sp)
{
    if (intStackShiftUp(sp->stack_a))
        stackPairLog(sp, RA_MSG);
}

void    rb_cmd(StackPair *sp)
{
    if (intStackShiftUp(sp->stack_b))
        stackPairLog(sp, RB_MSG);
}
void    rr_cmd(StackPair *sp)
{
    if (intStackShiftUp(sp->stack_a) || intStackShiftUp(sp->stack_b))
        stackPairLog(sp, RR_MSG);
}
