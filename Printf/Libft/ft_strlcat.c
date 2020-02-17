/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:58:36 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/26 05:58:29 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	i;
	size_t	srclen;

	destlen = 0;
	while (destlen < size && dest[destlen] != '\0')
		++destlen;
	srclen = ft_strlen(src);
	if (size != 0 && destlen < (size - 1))
	{
		i = destlen;
		while (i < (size - 1) && *src != '\0')
		{
			dest[i] = *src;
			++src;
			++i;
		}
		if (i < size)
			dest[i] = '\0';
	}
	return (destlen + srclen);
}
