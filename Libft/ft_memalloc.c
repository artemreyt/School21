/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:46:10 by creicher          #+#    #+#             */
/*   Updated: 2019/09/11 23:38:43 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;

	area = (unsigned char *)malloc(size);
	if (area)
	{
		size_t i;

		i = 0;
		while (i < size)
			area[i++] = 0;
	}
	return ((void *)area);
}
