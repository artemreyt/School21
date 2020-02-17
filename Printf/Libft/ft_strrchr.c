/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:05:18 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/22 04:23:59 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	sarrlen;

	ch = (char)c;
	sarrlen = ft_strlen(s) + 1;
	s += sarrlen - 1;
	while (sarrlen != 0)
	{
		if (*s == ch)
		{
			return ((char*)s);
		}
		--s;
		--sarrlen;
	}
	return (NULL);
}
