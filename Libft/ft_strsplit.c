/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:12:35 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/11 17:37:45 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_parts(char const *s, char c)
{
	size_t parts;
	size_t	i;
	int		in_part;

	in_part = 0;
	parts = 0;
	i = 0;
	while (s[i])
	{
		if (!in_part && s[i] != c)
		{
			parts++;
			in_part = 1;
		}
		else if (in_part && s[i] == c)
			in_part = 0;
		i++;
	}
	return (parts);
}

static const char	*skip_delim(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static void			free_array(char ***array)
{
	size_t i;

	i = 0;
	while ((*array)[i])
		ft_strdel((*array) + i);
	free(*array);
	*array = NULL;
}

static char			*next_part(char const *s, char c)
{
	char	*new_part;
	char	*end;
	size_t	part_len;
	
	end = ft_strchr(s, c);
	if (!end)
		part_len = ft_strlen(s);
	else
		part_len = (size_t)(end - s);
	new_part = ft_strnew(part_len);
	
	if (new_part)
		ft_strncpy(new_part, s, part_len);
	return (new_part);
}
char			**ft_strsplit(char const *s, char c)
{
	size_t	parts;
	char	**array;
	
	parts = ft_count_parts(s, c);
	array = (char **)ft_memalloc((parts + 1) * sizeof(*array));
	if (array)
	{
		size_t	part;
		
		part = 0;
		while (part < parts)
		{
			s = skip_delim(s, c);
			array[part] = next_part(s, c);
			if (!array[part])
			{
				free_array(&array);
				break;
			}
			s += ft_strlen(array[part]);
			part++;
		}
	}
	return (array);
}