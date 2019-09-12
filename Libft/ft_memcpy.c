/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:25:28 by creicher          #+#    #+#             */
/*   Updated: 2019/09/12 21:59:41 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (src || dst)
	{
		unsigned char *dst_cast;
		unsigned char *src_cast;
		

		dst_cast = (unsigned char *)dst;
		src_cast = (unsigned char *)src;
		while (n > 0)
		{
			*dst_cast++ = *src_cast++;
			n--;
		}
	}
	return (dst);
}
