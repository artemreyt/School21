/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:32:39 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/11 14:44:26 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char	*mapped;
	
	mapped = ft_strnew(ft_strlen(s));
	if (mapped)
	{
		unsigned int i;

		i = 0;
		while (s[i])
			mapped[i] = f(i, s[i]);
	}
	return (mapped);
}