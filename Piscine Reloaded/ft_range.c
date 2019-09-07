/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:41:20 by creicher          #+#    #+#             */
/*   Updated: 2019/09/07 16:45:30 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *range;
	int i;
	int n;

	if (min >= max)
		return (NULL);
	n = max - min;
	range = (int *)malloc(n * sizeof(int));
	i = 0;
	while (i < n)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
