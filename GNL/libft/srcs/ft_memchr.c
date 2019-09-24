/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:28:08 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 21:30:14 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	casted;
	unsigned char	*str_cast;

	i = 0;
	casted = (unsigned char)c;
	str_cast = (unsigned char *)s;
	while (i < n)
	{
		if (str_cast[i] == casted)
			return (str_cast + i);
		i++;
	}
	return (NULL);
}
