/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:41:11 by exam              #+#    #+#             */
/*   Updated: 2020/02/15 18:20:00 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

static size_t	ft_wlen(const char *str, const char *delims)
{
	size_t	i;

	i = 0;
	if (str != NULL)
		while (str[i] != '\0' && ft_strchr(delims, str[i]) == NULL)
			++i;
	return (i);
}

static size_t	ft_wcount(const char *str, const char *delims)
{
	size_t	wl;
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && ft_strchr(delims, *str) != NULL)
			++str;
		wl = ft_wlen(str, delims);
		if (wl != 0)
			++count;
		str += wl;
	}
	return (count);
}

static char		**init(size_t wcount)
{
	char	**empty_arr;

	if (wcount == SIZE_MAX)
		return (NULL);
	empty_arr = (char**)malloc((wcount + 1) * sizeof(*empty_arr));
	if (empty_arr != NULL)
		empty_arr[wcount] = NULL;
	return (empty_arr);
}

static char		*get_word(const char *str, size_t wl)
{
	char	*word;

	if (wl == SIZE_MAX)
		return (NULL);
	word = (char*)malloc((wl + 1) * sizeof(*word));
	if (word != NULL)
	{
		ft_memcpy(word, str, wl);
		word[wl] = '\0';
	}
	return (word);
}

char			**ft_strdsplit(const char *s, const char *d)
{
	size_t	i;
	size_t	wl;
	char	**words;

	i = 0;
	words = NULL;
	if (s != NULL && d != NULL && (words = init(ft_wcount(s, d))) != NULL)
		while (*s != '\0')
		{
			while (*s != '\0' && ft_strchr(d, *s) != NULL)
				++s;
			if ((wl = ft_wlen(s, d)) != 0 &&
				(words[i] = get_word(s, wl)) == NULL)
			{
				wl = (size_t)(-1);
				while (++wl < i)
					free(words[wl]);
				free(words);
				return (NULL);
			}
			s += wl;
			++i;
		}
	return (words);
}
