#include "StackPair.h"
#include "IntStack.h"
#include "libft.h"
#include <stdlib.h>

void    stackPairInit(StackPair *sp, int log_fd)
{
    sp->stack_a = intStackCreate();
    sp->stack_b = intStackCreate();
    if (!sp->stack_a || !sp->stack_b)
    {
        intStackFree(&sp->stack_a);
        intStackFree(&sp->stack_b);
        return ;
    }
    if (log_fd < 0)
        sp->log_fd = -1;
    else
        sp->log_fd = log_fd;
}

StackPair   *stackPairCreate(int *arr, size_t n,  int log_fd)
{
    StackPair   *sp;

    sp = (StackPair *)malloc(sizeof(*sp));
    if (!sp)
        return (NULL);
    stackPairInit(sp, log_fd);
    while (n)
        intStackPush(sp->stack_a, arr[--n]);
    return (sp);
}

void        stackPairFree(StackPair **sp)
{
    if (!sp || !(*sp))
        return ;
    intStackFree(&(*sp)->stack_a);
    intStackFree(&(*sp)->stack_b);
    free(*sp);
    *sp = NULL;
}

void        stackPairLog(StackPair *sp, const char *msg)
{
    if (sp->log_fd >= 0)
        ft_putendl_fd(msg, sp->log_fd);
}
