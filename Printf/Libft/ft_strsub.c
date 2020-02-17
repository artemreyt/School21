/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:18:18 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/15 18:20:11 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL || len == SIZE_MAX)
	{
		return (NULL);
	}
	substr = (char*)malloc((len + 1) * sizeof(*substr));
	if (substr != NULL)
	{
		s += start;
		i = 0;
		while (i < len)
		{
			substr[i] = s[i];
			++i;
		}
		substr[len] = '\0';
	}
	return (substr);
}
