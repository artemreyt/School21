/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:32:39 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/13 13:20:38 by artemstarshov    ###   ########.fr       */
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
		{
			mapped[i] = f(i, s[i]);
			i++;
		}
	}
	return (mapped);
}