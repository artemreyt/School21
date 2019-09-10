/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:36:52 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 10:58:12 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char casted;
	unsigned char *b_casted;

	b_casted = (unsigned char *)b;
	casted = (unsigned char)c;
	while (len > 0)
	{
		b_casted[len - 1] = casted;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[n - 1] = (unsigned char)0;
		n--;
	}
}

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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	casted;
	size_t			i;
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	dst_cast = (unsigned char *)dst;
	src_cast = (unsigned char *)src;
	i = 0;
	casted = (unsigned char)c;
	while (i < n && (unsigned char)src_cast[i] != casted)
	{
		dst_cast[i] = src_cast[i];
		i++;
	}
	return (dst);
}

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

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	casted;
	unsigned char	*str_cast;


	i = 0;
	casted = (unsigned char)c;
	str_cast = (unsigned char *)s;
	while (i < n)
	{
		if (str_cast[i] == casted)
			return (str_cast + i);
		i++;
	}
	return (NULL);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_cast;
	unsigned char *s2_cast;

	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (n > 0 && *s1_cast == *s2_cast)
	{
		s1_cast++;
		s2_cast++;
	}
	return (*s1_cast - *s2_cast);
}