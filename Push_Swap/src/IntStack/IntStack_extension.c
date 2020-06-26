#include "IntStack.h"

int    intStackShiftUp(IntStack *stack)
{
    if (stack->size <= 1)
        return (0);
    stack->head = stack->head->next;
    stack->tail = stack->tail->next;
    return (1);
}

int    intStackShiftDown(IntStack *stack)
{
    if (stack->size <= 1)
        return (0);
    stack->head = stack->head->prev;
    stack->tail = stack->tail->prev;
    return (1);
}

int    intStackSwap(IntStack *stack)
{
    int buf;

    if (stack->size < 2)
        return (0);
    buf = stack->head->value;
    stack->head->value = stack->head->next->value;
    stack->head->next->value = buf;
    return (1);
}
