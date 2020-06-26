/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:12:10 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:34:30 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char casted;

	casted = (char)c;
	while (*s)
	{
		if (*s == casted)
			return ((char *)s);
		s++;
	}
	return (casted == *s ? (char *)s : NULL);
}
