/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:26:08 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:28:44 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	casted;
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	casted = (unsigned char)c;
	while (n)
	{
		*dst_cast = *src_cast;
		if (*dst_cast == casted)
			return ((void *)(dst_cast + 1));
		dst_cast++;
		src_cast++;
		n--;
	}
	return (NULL);
}
