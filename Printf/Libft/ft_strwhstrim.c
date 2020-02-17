/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwhstrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:54:15 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/25 23:03:52 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strwhstrim(char const *s, const char *whitespaces)
{
	size_t	slen;
	char	*trimmedstr;

	if (s == NULL || whitespaces == NULL)
		return (NULL);
	while (*s != '\0' && ft_strchr(whitespaces, *s) != NULL)
		++s;
	slen = ft_strlen(s);
	if (slen != 0)
	{
		--slen;
		while (s[slen] != '\0' && ft_strchr(whitespaces, s[slen]) != NULL)
			--slen;
		++slen;
	}
	trimmedstr = (char*)malloc((slen + 1) * sizeof(*trimmedstr));
	if (trimmedstr != NULL)
	{
		ft_memcpy(trimmedstr, s, slen);
		trimmedstr[slen] = '\0';
	}
	return (trimmedstr);
}
