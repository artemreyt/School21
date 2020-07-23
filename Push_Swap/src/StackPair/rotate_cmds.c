/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:45:58 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:46:11 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"
#include "int_stack.h"

void	ra_cmd(t_stack_pair *sp)
{
	if (int_stack_shift_up(sp->stack_a))
		stack_pair_log(sp, RA_MSG);
}

void	rb_cmd(t_stack_pair *sp)
{
	if (int_stack_shift_up(sp->stack_b))
		stack_pair_log(sp, RB_MSG);
}

void	rr_cmd(t_stack_pair *sp)
{
	if (int_stack_shift_up(sp->stack_a) || int_stack_shift_up(sp->stack_b))
		stack_pair_log(sp, RR_MSG);
}
