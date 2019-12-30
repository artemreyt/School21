/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:31:58 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:21:22 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_cast;
	unsigned char *s2_cast;

	if (n == 0)
		return (0);
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (n > 1 && *s1_cast == *s2_cast)
	{
		s1_cast++;
		s2_cast++;
		n--;
	}
	return ((int)(*s1_cast - *s2_cast));
}
