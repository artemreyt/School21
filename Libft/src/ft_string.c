/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:45:59 by creicher          #+#    #+#             */
/*   Updated: 2019/09/09 20:36:40 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	offset;
	size_t	pos;
	size_t	needle_len;
	size_t	haystack_len;
	char	stop_symbol;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	offset = 0;
	while (offset + needle_len <= haystack_len)
	{
		pos = needle_len - 1;
		while (pos >= 0 && needle[pos] == haystack[offset + pos ])
			pos--;
		if (pos == -1)
			return (haystack + offset);
		stop_symbol = haystack[offset + pos];
		while (pos >= 0 && needle[pos] != stop_symbol)
		{
			pos--;
			offset++;
		}
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle,
					size_t len)
{
	size_t	offset;
	size_t	pos;
	size_t	needle_len;
	size_t	haystack_len;
	char	stop_symbol;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	offset = 0;
	while (offset + needle_len <= haystack_len && offset + needle_len <= len)
	{
		pos = needle_len - 1;
		while (pos >= 0 && needle[pos] == haystack[offset + pos])
			pos--;
		if (pos == -1)
			return (haystack + offset);
		stop_symbol = haystack[offset + pos];
		while (pos >= 0 && needle[pos] != stop_symbol)
		{
			pos--;
			offset++;
		}
	}
	return (NULL);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n-- > 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_strreverse(char *str)
{
	size_t	str_len;
	size_t	i;
	char	buf;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len / 2)
	{
		buf = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = str[i]; 
		i++;
	}
}
