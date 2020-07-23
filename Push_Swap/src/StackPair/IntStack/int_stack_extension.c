/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_stack_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:41:33 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:42:19 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_stack.h"

int		int_stack_shift_up(t_int_stack *stack)
{
	if (stack->size <= 1)
		return (0);
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	return (1);
}

int		int_stack_shift_down(t_int_stack *stack)
{
	if (stack->size <= 1)
		return (0);
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	return (1);
}

int		int_stack_swap(t_int_stack *stack)
{
	int buf;

	if (stack->size < 2)
		return (0);
	buf = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = buf;
	return (1);
}

int		int_stack_peek_few(t_int_stack *stack, int *buffer, int n)
{
	int			i;
	t_int_node	*current;

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

int		int_stack_check_order(t_int_stack *stack, int n, int ascending)
{
	t_int_node	*current;

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
