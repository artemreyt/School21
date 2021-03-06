/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:46:10 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:39:06 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;
	size_t			i;

	area = (unsigned char *)malloc(size);
	if (area)
	{
		i = 0;
		while (i < size)
			area[i++] = 0;
	}
	return ((void *)area);
}
