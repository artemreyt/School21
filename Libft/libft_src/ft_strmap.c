/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:29:47 by creicher          #+#    #+#             */
/*   Updated: 2019/09/16 16:03:18 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mapped;
	size_t	i;

	if (!s)
		return (NULL);
	mapped = ft_strnew(ft_strlen(s));
	if (mapped)
	{
		i = 0;
		while (s[i])
		{
			mapped[i] = f(s[i]);
			i++;
		}
	}
	return (mapped);
}
