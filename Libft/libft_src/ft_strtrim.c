/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:06:05 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/16 16:16:00 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	size_t		s_len;
	const char	*whitespaces = " \t\n";

	if (!s)
		return (NULL);
	start = 0;
	s_len = ft_strlen(s);
	if (s_len)
	{
		while (s[start] && ft_strchr(whitespaces, (int)s[start]))
			start++;
		end = s_len;
		while (end && ft_strchr(whitespaces, (int)s[end - 1]))
			end--;
		if (end > start)
			return (ft_strsub(s, start, end - start));
	}
	return (ft_strnew(0));
}
