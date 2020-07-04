#include "IntStack.h"
#include "IntNode.h"
#include <stdlib.h>

void    intStackInit(IntStack *stack)
{
    if (!stack)
        return ;
    stack->size = 0;
    stack->head = NULL;
    stack->tail = NULL;
}


void    intStackPush(IntStack *stack, int value)
{
    IntNode_t *new;

    if (!stack)
        return ;
    new = createIntNode(value);
    if (!new)
        return ;
    if (stack->size == 0)
    {
        stack->head = new;
        stack->tail = new;
    }
    else
    {
        new->next = stack->head;
        new->prev = stack->tail;
        stack->head->prev = new;
        stack->tail->next = new;
        stack->head = new;
    }
    ++stack->size;
}

int     intStackPop(IntStack *stack, int *pop_value)
{
    IntNode_t *old_head;

    if (!stack || !stack->size)
        return (0);
    old_head = stack->head;
    if (pop_value)
        *pop_value = old_head->value;
    stack->head = stack->head->next;
    stack->tail->next = stack->head;
    stack->head->prev = stack->tail;
    free(old_head);
    if (--stack->size == 0)
    {
        stack->head = NULL;
        stack->tail = NULL;
    }
    return (1);
}

int     intStackPeek(IntStack *stack, int *value)
{
    if (!stack || !stack->size)
        return (0);
    if (value)
        *value = stack->head->value;
    return (1);
}

