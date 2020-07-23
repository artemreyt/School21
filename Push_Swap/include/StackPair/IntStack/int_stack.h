#ifndef INT_STACK_H
#define INT_STACK_H

#include "int_node.h"
#include <stdlib.h>


struct  s_int_stack
{
    t_int_node   *head;
    t_int_node   *tail;
    int         size;
};
typedef struct s_int_stack   t_int_stack;

t_int_stack    *intStackCreate();
void        int_stack_free(t_int_stack **stack);

void        int_stack_init(t_int_stack *stack);
void        int_stack_push(t_int_stack *stack, int value);
int         int_stack_pop(t_int_stack *stack, int *pop_value);
int         int_stack_peek(t_int_stack *stack, int *value);

/*
 * * Special extensions for project Push_Swap
 *
*/
int         int_stack_shift_up(t_int_stack *stack);
int         int_stack_shift_down(t_int_stack *stack);
int         int_stack_swap(t_int_stack *stack);
int         int_stack_peek_few(t_int_stack *stack, int *buffer, int n);
int         int_stack_check_order(t_int_stack *stack, int n, int ascending);



#endif
