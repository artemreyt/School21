/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:29:47 by creicher          #+#    #+#             */
/*   Updated: 2019/09/11 13:30:48 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mapped;

	mapped = ft_strnew(ft_strlen(s));
	if (mapped)
	{
		size_t	i;

		i = 0;
		while (s[i])
		{
			mapped[i] = f(s[i]);
			i++;
		}
	}
	return (mapped);
}
