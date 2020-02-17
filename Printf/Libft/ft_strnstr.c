/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 02:52:17 by ecathryn          #+#    #+#             */
/*   Updated: 2019/10/17 07:58:42 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((needle[j] != '\0') && needle[j] == haystack[i + j])
		{
			if (i + j >= len)
				return (NULL);
			++j;
		}
		if (needle[j] == '\0')
			return ((char*)(haystack + i));
		++i;
	}
	return (NULL);
}
