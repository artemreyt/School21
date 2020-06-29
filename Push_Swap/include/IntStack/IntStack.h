#ifndef INTSTACK_H
#define INTSTACK_H

#include "IntNode.h"
#include <stdlib.h>


struct  s_IntStack
{
    IntNode_t   *head;
    IntNode_t   *tail;
    size_t      size;
};
typedef struct s_IntStack   IntStack;

void        intStackInit(IntStack *stack);
void        intStackPush(IntStack *stack, int value);
int         intStackPop(IntStack *stack, int *pop_value);
int         intStackPeek(IntStack *stack, int *value);
void        intStackFree(IntStack *stack);

/*
 * Special extensions for project Push_Swap
 */
int         intStackShiftUp(IntStack *stack);
int         intStackShiftDown(IntStack *stack);
int         intStackSwap(IntStack *stack);
int         intStackPeekFew(IntStack *stack, int *buffer, int n);
int         intStackCheckOrder(IntStack *stack, int n, int ascending);



#endif
