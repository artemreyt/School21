#include "StackPair.h"
#include "IntStack.h"
#include "libft.h"
#include <stdlib.h>

void    stackPairInit(StackPair *sp, int log_fd)
{
    sp->stack_a = (IntStack *)malloc(sizeof(*sp->stack_a));
    sp->stack_b = (IntStack *)malloc(sizeof(*sp->stack_b));
    if (!sp->stack_a || !sp->stack_b)
    {
        free(sp->stack_a);
        free(sp->stack_b);
        return ;
    }
    intStackInit(sp->stack_a);
    intStackInit(sp->stack_b);
    if (log_fd < 0)
        sp->log_fd = -1;
    else
        sp->log_fd = log_fd;
}

StackPair   *stackPairCreate(int *arr, size_t n,  int log_fd)
{
    StackPair   *sp;
    size_t      i;

    sp = (StackPair *)malloc(sizeof(*sp));
    if (!sp)
        return (NULL);
    stackPairInit(sp, log_fd);

    i = 0;
    while (i < n)
        intStackPush(sp->stack_a, arr[i++]);

    return (sp);
}

void        stackPairLog(StackPair *sp, const char *msg)
{
    if (sp->log_fd >= 0)
        ft_putendl_fd(msg, sp->log_fd);
}

