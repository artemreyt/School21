/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:10:22 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 12:14:30 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "stack_pair.h"
#include "get_next_line.h"

static int	execute_command(t_stack_pair *sp, char *cmd)
{
	if (!ft_strcmp(cmd, SA_MSG))
		sa_cmd(sp);
	else if (!ft_strcmp(cmd, SB_MSG))
		sb_cmd(sp);
	else if (!ft_strcmp(cmd, SS_MSG))
		ss_cmd(sp);
	else if (!ft_strcmp(cmd, PA_MSG))
		pa_cmd(sp);
	else if (!ft_strcmp(cmd, PB_MSG))
		pb_cmd(sp);
	else if (!ft_strcmp(cmd, RA_MSG))
		ra_cmd(sp);
	else if (!ft_strcmp(cmd, RB_MSG))
		rb_cmd(sp);
	else if (!ft_strcmp(cmd, RR_MSG))
		rr_cmd(sp);
	else if (!ft_strcmp(cmd, RRA_MSG))
		rra_cmd(sp);
	else if (!ft_strcmp(cmd, RRB_MSG))
		rrb_cmd(sp);
	else if (!ft_strcmp(cmd, RRR_MSG))
		rrr_cmd(sp);
	else
		return (0);
	return (1);
}

/*
	** TODO: read from file
*/

static int	checker(t_stack_pair *sp, int size, int fd)
{
	char *cmd;

	fd++;
	while (get_next_line(STDIN_FILENO, &cmd) > 0)
	{
		if (!execute_command(sp, cmd))
		{
			free(cmd);
			return (ERROR_CODE);
		}
		free(cmd);
	}
	if (!stack_pair_check_order(sp, A_STACK, size) || sp->stack_b->size)
		return (KO_CODE);
	return (OK_CODE);
}

int			launch_checker(int argc, char **argv)
{
	int				*arr;
	int				retv;
	int				size;
	t_stack_pair	*sp;

	if (!checker_parse_arguments(argc, argv, &arr, &size))
		retv = ERROR_CODE;
	else
	{
		sp = stack_pair_create(arr, size, -1);
		retv = checker(sp, size, STDIN_FILENO);
		stack_pair_free(&sp);
		free(arr);
	}
	return (retv);
}
