/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 04:05:28 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/22 05:32:03 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len == 0)
	{
		return (0);
	}
	i = 1;
	while (i < len && *s1 != '\0' && (t_uchar)(*s1) == (t_uchar)(*s2))
	{
		++s1;
		++s2;
		++i;
	}
	return ((int)((t_uchar)(*s1) - (t_uchar)(*s2)));
}
