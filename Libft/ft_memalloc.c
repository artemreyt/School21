/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:46:10 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 22:58:31 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;

	area = (unsigned char *)malloc(size);
	if (area)
	{
		while (size)
			area[size--] = 0;
	}
	return ((void *)area);
}
