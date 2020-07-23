#include "int_stack.h"
#include <stdlib.h>

t_int_stack    *intStackCreate()
{
    t_int_stack *stack;

    stack = (t_int_stack *)malloc(sizeof(t_int_stack));
    if (stack == NULL)
        return NULL;
    int_stack_init(stack);
    return (stack);
}

void        int_stack_free(t_int_stack **stack)
{
    if (!stack || !(*stack))
        return ;
    while (int_stack_pop(*stack, NULL))
        continue ;
    free(*stack);
    *stack = NULL;
}