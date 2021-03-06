/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:24:26 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:35:46 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
