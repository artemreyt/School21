/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 07:25:02 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/15 18:25:47 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

static inline size_t	get_mul_no_overflow(void)
{
	unsigned char	*c;
	size_t			r;

	r = 0;
	c = (unsigned char *)&r;
	c += sizeof(size_t) / 2;
	*c = (unsigned char)1;
	return (r);
}

void					*ft_mallocarray(size_t nmemb, size_t size)
{
	size_t	mul_no_ovr;

	if (size == 0 || nmemb == 0)
		return (NULL);
	mul_no_ovr = get_mul_no_overflow();
	if ((nmemb >= mul_no_ovr || size >= mul_no_ovr) &&
		UINTPTR_MAX / nmemb < size)
		return (NULL);
	return (malloc(nmemb * size));
}
