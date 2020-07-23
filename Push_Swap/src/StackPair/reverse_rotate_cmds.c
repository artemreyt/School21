/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:45:39 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:45:51 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"
#include "int_stack.h"

void	rra_cmd(t_stack_pair *sp)
{
	if (int_stack_shift_down(sp->stack_a))
		stack_pair_log(sp, RRA_MSG);
}

void	rrb_cmd(t_stack_pair *sp)
{
	if (int_stack_shift_down(sp->stack_b))
		stack_pair_log(sp, RRB_MSG);
}

void	rrr_cmd(t_stack_pair *sp)
{
	if (int_stack_shift_down(sp->stack_a) || int_stack_shift_down(sp->stack_b))
		stack_pair_log(sp, RRR_MSG);
}
