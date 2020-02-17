/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:04:28 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 21:01:04 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_byte_set(void *s, int c, size_t n)
{
	t_uchar		*arr;
	t_uchar		filler;

	filler = (t_uchar)c;
	arr = (t_uchar*)s;
	while (n != 0)
	{
		*arr = filler;
		++arr;
		--n;
	}
}

void				*ft_memset(void *s, int c, size_t n)
{
	size_t		max_filler;
	size_t		max_n;
	size_t		*max_arr;

	max_arr = (size_t*)s;
	max_n = n / sizeof(size_t);
	if (max_n != 0)
	{
		ft_byte_set(&max_filler, c, sizeof(size_t));
		while (max_n != 0)
		{
			*max_arr = max_filler;
			++max_arr;
			--max_n;
		}
	}
	max_n = n % sizeof(size_t);
	ft_byte_set(max_arr, c, max_n);
	return (s);
}
