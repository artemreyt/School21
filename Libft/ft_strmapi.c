/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:32:39 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/15 21:41:31 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	i;

	mapped = ft_strnew(ft_strlen(s));
	if (mapped)
	{
		i = 0;
		while (s[i])
		{
			mapped[i] = f(i, s[i]);
			i++;
		}
	}
	return (mapped);
}
