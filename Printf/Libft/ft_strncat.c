/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:26:58 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 02:04:44 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ds;

	ds = dest + ft_strlen(dest);
	while (n != 0 && *src != '\0')
	{
		*ds = *src;
		++ds;
		++src;
		--n;
	}
	*ds = '\0';
	return (dest);
}
