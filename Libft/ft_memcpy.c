/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:25:28 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 21:25:42 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_cast;
	unsigned char *src_cast;

	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;

	while (n > 0)
	{
		dst_cast[n - 1] = src_cast[n - 1];
		n--;
	}
	return (dst);
}
