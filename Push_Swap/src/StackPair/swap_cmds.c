#include "stack_pair.h"
#include "int_stack.h"

int    sa_cmd(t_stack_pair *sp)
{
    int res;

    res = int_stack_swap(sp->stack_a);
    if (res)
        stack_pair_log(sp, SA_MSG);
    return (res);
}

int    sb_cmd(t_stack_pair *sp)
{
    int res;

    res = int_stack_swap(sp->stack_b);
    if (res)
        stack_pair_log(sp, SB_MSG);
    return (res);
}

int    ss_cmd(t_stack_pair *sp)
{
    if (int_stack_swap(sp->stack_a) || int_stack_swap(sp->stack_b))
    {
        stack_pair_log(sp, SS_MSG);
        return (1);
    }
    return (0);
}
