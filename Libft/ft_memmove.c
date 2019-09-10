/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:27:37 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 21:27:49 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_cast;
	unsigned char *src_cast;
	unsigned char *buffer;

	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	buffer = (unsigned char *)malloc(len);
	buffer = (unsigned char *)ft_memcpy(buffer, src, len);
	while (len > 0)
	{
		dst_cast[len - 1] = buffer[len - 1];
		len--;
	}
	free(buffer);
	return (dst);
}
