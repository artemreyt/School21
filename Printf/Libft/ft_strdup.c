/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 04:16:57 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 00:14:54 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	duplen;

	duplen = ft_strlen(s);
	dup = (char*)malloc((duplen + 1) * sizeof(*dup));
	if (dup != NULL)
	{
		dup[duplen] = '\0';
		ft_memcpy(dup, s, duplen);
	}
	return (dup);
}
