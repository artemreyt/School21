/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:09:06 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 14:11:16 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHMS_H
# define FT_ALGORITHMS_H

union	u_int32
{
	int				x;
	unsigned char	bytes[4];
};

/*
	** works only with arrays
	** on the heap memory segment
*/
void	radix_sort(int *arr, int n);

/*
	** m - max size of chunk to sort by selection sort (optimization) if m == 0
	** then all chunks will be sorted by quick push_swap_sort algorithm
*/
void	quick_sort(int *arr, int n, int m);

void	selection_sort(int *arr, int n);

#endif
