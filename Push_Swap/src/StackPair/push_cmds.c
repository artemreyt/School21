/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:43:37 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:45:19 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"
#include "int_stack.h"

void	pa_cmd(t_stack_pair *sp)
{
	int b_top;

	if (int_stack_pop(sp->stack_b, &b_top))
	{
		int_stack_push(sp->stack_a, b_top);
		stack_pair_log(sp, PA_MSG);
	}
}

void	pb_cmd(t_stack_pair *sp)
{
	int a_top;

	if (int_stack_pop(sp->stack_a, &a_top))
	{
		int_stack_push(sp->stack_b, a_top);
		stack_pair_log(sp, PB_MSG);
	}
}
