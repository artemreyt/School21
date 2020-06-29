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

int    intStackPeekFew(IntStack *stack, int *buffer, int n)
{
    int         i;
    IntNode_t   *current;

    if (stack->size < n)
        return (0);
    i = 0;
    current = stack->head;
    while (i < n)
    {
        buffer[i] = current->value;
        current = current->next;
        ++i;
    }
    return (1);
}

int         intStackCheckOrder(IntStack *stack, int n, int ascending)
{
    IntNode_t *current;

    if (n < 0 || stack->size < n)
        return (-1);
    current = stack->head;
    while (n-- > 1)
    {
        if ((ascending && current->value > current->next->value) ||
                (!ascending && current->value < current->next->value))
            return (0);
        current = current->next;
    }
    return (1);
}

