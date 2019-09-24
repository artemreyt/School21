/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:23:44 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 21:23:54 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char casted;
	unsigned char *b_casted;

	b_casted = (unsigned char *)b;
	casted = (unsigned char)c;
	while (len > 0)
	{
		b_casted[len - 1] = casted;
		len--;
	}
	return (b);
}
