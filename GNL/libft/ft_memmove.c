/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:27:37 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:29:44 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_cast;
	unsigned char *src_cast;

	if (dst || src)
	{
		if (dst < src)
			return (ft_memcpy(dst, src, len));
		else if (dst > src)
		{
			dst_cast = (unsigned char *)dst;
			src_cast = (unsigned char *)src;
			while (len)
			{
				dst_cast[len - 1] = src_cast[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
