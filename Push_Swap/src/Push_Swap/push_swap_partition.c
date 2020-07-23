/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:47:52 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 13:33:04 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_pair.h"
#include "int_stack.h"
#include "ft_printf.h"
#include <stdlib.h>

static int	get_number(t_stack_pair *sp, t_stack_side side)
{
	int	number;

	if (!stack_pair_peek(sp, side, &number))
		exit(EXIT_FAILURE);
	return (number);
}

static void	push(t_stack_pair *sp, t_stack_side side)
{
	if (side == A_STACK)
		pb_cmd(sp);
	else
		pa_cmd(sp);
}

static void	rotate(t_stack_pair *sp, t_stack_side side, int num)
{
	void	(*rotator)(t_stack_pair *);

	if (num > 0)
	{
		if (side == A_STACK)
			rotator = ra_cmd;
		else
			rotator = rb_cmd;
	}
	else
	{
		if (side == A_STACK)
			rotator = rra_cmd;
		else
			rotator = rrb_cmd;
	}
	num = num < 0 ? -num : num;
	while (num)
	{
		rotator(sp);
		--num;
	}
}

/*
	** checks for need to push top element from stack to another one
	** if need, do that and return 1, else rotate up and return 0
*/

static int	compare_and_push(t_stack_pair *sp, t_chunk_info *info, int pivot)
{
	int number;

	number = get_number(sp, info->side);
	if ((info->side == A_STACK && number >= pivot) ||
		(info->side == B_STACK && number < pivot))
	{
		rotate(sp, info->side, +1);
		return (0);
	}
	push(sp, info->side);
	return (1);
}

void		push_swap_partition(t_stack_pair *sp,
						const int *arr, t_chunk_info *chunk_info)
{
	int	rotate_num;
	int	pivot;
	int	need_to_push;
	int	stack_len;

	if (chunk_info->side == A_STACK)
		stack_len = sp->stack_a->size;
	else
		stack_len = sp->stack_b->size;
	pivot = arr[chunk_info->start_index + chunk_info->length / 2];
	rotate_num = 0;
	if (chunk_info->side == A_STACK)
		need_to_push = chunk_info->length / 2;
	else
		need_to_push = chunk_info->length - chunk_info->length / 2;
	while (need_to_push > 0)
	{
		if (compare_and_push(sp, chunk_info, pivot))
			--need_to_push;
		else
			++rotate_num;
	}
	if (chunk_info->length < stack_len)
		rotate(sp, chunk_info->side, -rotate_num);
}
