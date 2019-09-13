/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:10:56 by creicher          #+#    #+#             */
/*   Updated: 2019/09/13 11:08:26 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		is_terminated;
	size_t	dst_len;


	is_terminated = 0;
	i = dst_len = ft_strlen(dst);
	if (dst_len > size)
		return (size + ft_strlen(src));
	while (i < size)
	{
		dst[i] = *src;
		if (*src == '\0')
		{
			is_terminated = 1;
			break;
		}
		i++;
		src++;
	}

	while (*src++)
		i++;
	if (!is_terminated)
		dst[size - 1] = '\0';
	return (i);
}

int main()
{
	char str[20] = "hello, ";
	//size_t len = strlcat(str, "world!", 4);
	size_t len = ft_strlcat(str, "world!", 4);
	ft_putendl(str);
	ft_putnbr(len);
}
