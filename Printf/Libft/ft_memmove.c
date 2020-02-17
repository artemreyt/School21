/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:29:21 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/24 00:11:20 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_memrbtcpy(void *dest, const void *src, size_t n)
{
	const t_uchar	*sr;
	t_uchar			*ds;

	sr = (const t_uchar*)src;
	ds = (t_uchar*)dest;
	while (n != 0)
	{
		*ds = *sr;
		--ds;
		--sr;
		--n;
	}
	return (dest);
}

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	const size_t	*sr;
	size_t			*ds;

	if (dest != NULL || src != NULL)
	{
		ft_memrbtcpy((t_uchar*)dest + n - 1,
				(t_uchar*)src + n - 1, n % sizeof(size_t));
		n -= n % sizeof(size_t);
		sr = (size_t*)((const t_uchar*)src + n) - 1;
		ds = (size_t*)((t_uchar*)dest + n) - 1;
		n /= sizeof(size_t);
		while (n != 0)
		{
			*ds = *sr;
			--sr;
			--ds;
			--n;
		}
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest != src)
	{
		if (dest < src)
		{
			ft_memcpy(dest, src, n);
		}
		else
		{
			ft_memrcpy(dest, src, n);
		}
	}
	return (dest);
}
