/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:03:41 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 12:05:28 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_pair.h"

struct						s_chunk_info
{
	t_stack_side	side;
	int				start_index;
	int				length;
};
typedef struct s_chunk_info	t_chunk_info;

void						launch_push_swap(int *arr, int n);
void						push_swap(t_stack_pair *sp, int *arr,
									t_chunk_info *chunk_info);
void						push_swap_partition(t_stack_pair *sp,
									const int *arr, t_chunk_info *chunk_info);
void						push_swap_sort(t_stack_pair *sp,
									t_chunk_info *chunk_info);

#endif
