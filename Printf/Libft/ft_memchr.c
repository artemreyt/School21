/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:46:20 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 00:11:09 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	t_uchar			filler;
	const t_uchar	*arr;

	filler = (t_uchar)c;
	arr = (const t_uchar*)s;
	i = 0;
	while (i < n)
	{
		if (arr[i] == filler)
		{
			return ((void*)(arr + i));
		}
		++i;
	}
	return (NULL);
}
