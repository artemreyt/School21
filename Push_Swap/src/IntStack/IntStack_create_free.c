#include "IntStack.h"
#include <stdlib.h>

IntStack    *intStackCreate()
{
    IntStack *stack;

    stack = (IntStack *)malloc(sizeof(IntStack));
    if (stack == NULL)
        return NULL;
    intStackInit(stack);
    return (stack);
}

void        intStackFree(IntStack **stack)
{
    if (!stack || !(*stack))
        return ;
    while (intStackPop(*stack, NULL))
        continue ;
    free(*stack);
    *stack = NULL;
}