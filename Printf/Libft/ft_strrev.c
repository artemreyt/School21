/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:50:45 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/23 18:39:16 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	j;

	if (s != NULL)
	{
		i = 0;
		j = ft_strlen(s);
		while (i < j)
		{
			ft_swapc(s + i, s + j);
			++i;
			--j;
		}
	}
	return (s);
}
