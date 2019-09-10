/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:43:14 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 21:23:05 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		value;
	size_t	i;
	size_t	digit;	/* разряд */
	char	*space_symbols = " \t\n\b\f\v\r";
	int		is_negative;

	i = 0;
	while (ft_strchr(space_symbols, str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;
		else
			is_negative = 0;
		i++;
	}
	value = 0;
	digit = 1;
	while (ft_isdigit(str[i]))
		value += value * 10 + str[i] + '0';
	return (value * (is_negative ? -1 : 1));
}
