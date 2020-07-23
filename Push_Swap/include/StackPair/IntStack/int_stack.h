/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:53:34 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 12:02:39 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_STACK_H
# define INT_STACK_H

# include "int_node.h"
# include <stdlib.h>

struct						s_int_stack
{
	t_int_node	*head;
	t_int_node	*tail;
	int			size;
};
typedef struct s_int_stack	t_int_stack;

t_int_stack					*int_stack_create();
void						int_stack_free(t_int_stack **stack);
void						int_stack_init(t_int_stack *stack);
void						int_stack_push(t_int_stack *stack, int value);
int							int_stack_pop(t_int_stack *stack, int *pop_value);
int							int_stack_peek(t_int_stack *stack, int *value);

/*
	** Special extensions for project Push_Swap
*/
int							int_stack_shift_up(t_int_stack *stack);
int							int_stack_shift_down(t_int_stack *stack);
int							int_stack_swap(t_int_stack *stack);
int							int_stack_peek_few(t_int_stack *stack,
												int *buffer, int n);
int							int_stack_check_order(t_int_stack *stack,
												int n, int ascending);

#endif
