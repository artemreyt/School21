/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:21:11 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 21:22:26 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_uchar			ch;
	t_uchar			*destination;
	const t_uchar	*source;

	ch = (t_uchar)c;
	destination = (t_uchar*)dest;
	source = (const t_uchar*)src;
	while (n != 0)
	{
		*destination = *source;
		if (*destination == ch)
		{
			return ((void*)(destination + 1));
		}
		++destination;
		++source;
		--n;
	}
	return (NULL);
}
