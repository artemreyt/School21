/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_stack_create_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:40:31 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:41:22 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_stack.h"
#include <stdlib.h>

t_int_stack	*int_stack_create(void)
{
	t_int_stack *stack;

	stack = (t_int_stack *)malloc(sizeof(t_int_stack));
	if (stack == NULL)
		return (NULL);
	int_stack_init(stack);
	return (stack);
}

void		int_stack_free(t_int_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	while (int_stack_pop(*stack, NULL))
		continue ;
	free(*stack);
	*stack = NULL;
}
