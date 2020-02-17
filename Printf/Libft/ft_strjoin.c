/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:43:00 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/23 19:12:03 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = (char*)malloc((s1len + s2len + 1) * sizeof(*join));
	if (join != NULL)
	{
		ft_memcpy(join, s1, s1len);
		ft_memcpy(join + s1len, s2, s2len);
		join[s1len + s2len] = '\0';
	}
	return (join);
}
