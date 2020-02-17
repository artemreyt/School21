/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:28:20 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/15 18:20:08 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (size != SIZE_MAX)
	{
		str = (char*)ft_memalloc(size + 1);
	}
	return (str);
}
