/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:38:42 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:39:25 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_stack.h"
#include "int_node.h"
#include <stdlib.h>

void	int_stack_init(t_int_stack *stack)
{
	if (!stack)
		return ;
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

void	int_stack_push(t_int_stack *stack, int value)
{
	t_int_node *new;

	if (!stack)
		return ;
	new = create_int_node(value);
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

int		int_stack_pop(t_int_stack *stack, int *pop_value)
{
	t_int_node *old_head;

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

int		int_stack_peek(t_int_stack *stack, int *value)
{
	if (!stack || !stack->size)
		return (0);
	if (value)
		*value = stack->head->value;
	return (1);
}
