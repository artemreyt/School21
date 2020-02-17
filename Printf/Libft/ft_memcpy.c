/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:11:33 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/15 15:06:24 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_membtcpy(void *dest, const void *src, size_t n)
{
	const t_uchar	*sr;
	t_uchar			*ds;

	sr = (const t_uchar*)src;
	ds = (t_uchar*)dest;
	while (n != 0)
	{
		*ds = *sr;
		++ds;
		++sr;
		--n;
	}
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	const size_t	*sr;
	size_t			*ds;

	if (dest != src)
	{
		ft_membtcpy(dest, src, n % sizeof(size_t));
		sr = (const size_t*)((t_uchar*)src + n % sizeof(size_t));
		ds = (size_t*)((t_uchar*)dest + n % sizeof(size_t));
		n = (n - n % sizeof(size_t)) / sizeof(size_t);
		while (n != 0)
		{
			*ds = *sr;
			++ds;
			++sr;
			--n;
		}
	}
	return (dest);
}
