/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:27:37 by creicher          #+#    #+#             */
/*   Updated: 2019/09/12 21:59:36 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst || src)
	{
		if (dst < src)
			return (ft_memcpy(dst, src, len));
		else if (dst > src)
		{
			unsigned char *dst_cast;
			unsigned char *src_cast;

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

// int main()
// {
// 	char str[] = "abcdefghij";
// 	ft_memmove(str + 2, str + 3, 3);

// 	ft_putendl(str);
// }
