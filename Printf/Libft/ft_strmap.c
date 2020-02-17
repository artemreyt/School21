/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:23:21 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/22 23:59:30 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mappedstr;
	size_t	len_mapstr;
	size_t	i;

	mappedstr = NULL;
	if (s != NULL && f != NULL)
	{
		len_mapstr = ft_strlen(s);
		mappedstr = (char*)malloc((len_mapstr + 1) * sizeof(*mappedstr));
		if (mappedstr != NULL)
		{
			i = 0;
			while (i < len_mapstr)
			{
				mappedstr[i] = f(s[i]);
				++i;
			}
			mappedstr[len_mapstr] = '\0';
		}
	}
	return (mappedstr);
}
