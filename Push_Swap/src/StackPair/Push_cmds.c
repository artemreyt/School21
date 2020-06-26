#include "StackPair.h"
#include "IntStack.h"

void    pa_cmd(StackPair *sp)
{
    int b_top;

    if (intStackPop(sp->stack_b, &b_top))
    {
        intStackPush(sp->stack_a, b_top);
        stackPairLog(sp, PA_MSG);
    }
}
void    pb_cmd(StackPair *sp)
{
    int a_top;

    if (intStackPop(sp->stack_a, &a_top))
    {
        intStackPush(sp->stack_b, a_top);
        stackPairLog(sp, PB_MSG);
    }
}
