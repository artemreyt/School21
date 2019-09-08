/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:45:59 by creicher          #+#    #+#             */
/*   Updated: 2019/09/08 23:19:04 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i = 0;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char *res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!res)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strcpy(res, src);
	return (res);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	ft_strcpy(s1 + i, s2);
	return (s1);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	ft_strncpy(s1 + i, s2, n);
	return (s1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	ft_strncat(s1 + i, src, size - i - 1);
	return (ft_strlen(dst));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return s;
		s++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (s[i] == (char)c)
			return (s + i);
		i--;
	}
	return (NULL);
}












































