/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:48:59 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:50:53 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"
#include "int_stack.h"

static t_int_stack	*get_stack(t_stack_pair *sp, t_stack_side side)
{
	if (side == A_STACK)
		return (sp->stack_a);
	return (sp->stack_b);
}

int					stack_pair_peek(t_stack_pair *sp,
						t_stack_side side, int *res)
{
	return (int_stack_peek(get_stack(sp, side), res));
}

int					stack_pair_peek_few(t_stack_pair *sp,
						t_stack_side side, int *buffer, int n)
{
	return (int_stack_peek_few(get_stack(sp, side), buffer, n));
}

int					stack_pair_swap(t_stack_pair *sp, t_stack_side side)
{
	int res;

	if (side == A_STACK)
		res = sa_cmd(sp);
	else
		res = sb_cmd(sp);
	return (res);
}

int					stack_pair_check_order(t_stack_pair *sp,
						t_stack_side side, int n)
{
	int ascending;

	if (side == A_STACK)
		ascending = 1;
	else
		ascending = 0;
	return (int_stack_check_order(get_stack(sp, side), n, ascending));
}
