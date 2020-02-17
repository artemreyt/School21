/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 02:52:17 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/22 04:18:48 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
	{
		return ((char*)haystack);
	}
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while ((needle[j] != '\0') && needle[j] == haystack[i + j])
		{
			++j;
		}
		if (needle[j] == '\0')
		{
			return ((char*)(haystack + i));
		}
		++i;
	}
	return (NULL);
}
