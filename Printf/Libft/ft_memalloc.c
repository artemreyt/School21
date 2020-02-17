/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:14:23 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/20 06:30:02 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	t_uchar	*mem;

	mem = NULL;
	if (size != 0)
	{
		mem = (t_uchar*)malloc(size * sizeof(*mem));
		if (mem != NULL)
		{
			ft_bzero(mem, size);
		}
	}
	return ((void*)mem);
}
