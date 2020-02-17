/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:52:35 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/22 23:59:31 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mappedstr;
	unsigned int	len_mapstr;
	unsigned int	i;

	mappedstr = NULL;
	if (s != NULL && f != NULL)
	{
		len_mapstr = (unsigned int)ft_strlen(s);
		mappedstr = (char*)malloc((len_mapstr + 1) * sizeof(*mappedstr));
		if (mappedstr != NULL)
		{
			i = 0;
			while (i < len_mapstr)
			{
				mappedstr[i] = f(i, s[i]);
				++i;
			}
			mappedstr[len_mapstr] = '\0';
		}
	}
	return (mappedstr);
}
