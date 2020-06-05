/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:46:28 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:47:14 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_pair.h"
#include "int_stack.h"
#include "libft.h"
#include <stdlib.h>

void			stack_pair_init(t_stack_pair *sp, int log_fd)
{
	sp->stack_a = int_stack_create();
	sp->stack_b = int_stack_create();
	if (!sp->stack_a || !sp->stack_b)
	{
		int_stack_free(&sp->stack_a);
		int_stack_free(&sp->stack_b);
		return ;
	}
	if (log_fd < 0)
		sp->log_fd = -1;
	else
		sp->log_fd = log_fd;
}

t_stack_pair	*stack_pair_create(int *arr, size_t n, int log_fd)
{
	t_stack_pair	*sp;

	sp = (t_stack_pair *)malloc(sizeof(*sp));
	if (!sp)
		return (NULL);
	stack_pair_init(sp, log_fd);
	while (n)
		int_stack_push(sp->stack_a, arr[--n]);
	return (sp);
}

void			stack_pair_free(t_stack_pair **sp)
{
	if (!sp || !(*sp))
		return ;
	int_stack_free(&(*sp)->stack_a);
	int_stack_free(&(*sp)->stack_b);
	free(*sp);
	*sp = NULL;
}

void			stack_pair_log(t_stack_pair *sp, const char *msg)
{
	if (sp->log_fd >= 0)
		ft_putendl_fd(msg, sp->log_fd);
}
