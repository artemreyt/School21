/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 03:56:14 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/21 00:11:51 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_uchar	*arr1;
	const t_uchar	*arr2;

	if (s1 != NULL || s2 != NULL)
	{
		arr1 = (const t_uchar*)s1;
		arr2 = (const t_uchar*)s2;
		while (n != 0)
		{
			if (*arr1 != *arr2)
			{
				return ((int)(*arr1 - *arr2));
			}
			++arr1;
			++arr2;
			--n;
		}
	}
	return (0);
}
