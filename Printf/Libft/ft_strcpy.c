/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:54:57 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 21:30:08 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ds;

	ds = dest;
	while (*src != '\0')
	{
		*ds = *src;
		++ds;
		++src;
	}
	*ds = '\0';
	return (dest);
}
