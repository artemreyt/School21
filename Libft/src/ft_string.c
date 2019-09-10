/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:45:59 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 20:31:16 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
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
	size_t i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < len && src[i] == '\0')
		dst[i++] = '\0';
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
	ft_strncat(dst + i, src, size - i - 1);
	return (ft_strlen(dst));
}

char	*ft_strchr(const char *s, int c)
{
	char casted;

	casted = (char)c;

	while (*s)
	{
		if (*s == casted)
			return ((char *)s);
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
			return ((char *)s + i);
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
		pos = needle_len;	/* because pos can't be lower than 0 */
		while (pos > 0 && needle[pos - 1] == haystack[offset + pos - 1])
			pos--;
		if (pos == 0)
			return ((char *)haystack + offset);
		stop_symbol = haystack[offset + pos - 1];
		while (pos > 0 && needle[pos] != stop_symbol)
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
		pos = needle_len;
		while (pos > 0 && needle[pos - 1] == haystack[offset + pos - 1])
			pos--;
		if (pos == 0)
			return ((char *)haystack + offset);
		stop_symbol = haystack[offset + pos - 1];
		while (pos > 0 && needle[pos - 1] != stop_symbol)
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
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n-- > 0)
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}

int		ft_strequ(char const *s1, char const *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}
