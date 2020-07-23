/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:02:26 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 14:04:37 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int			ft_atoi_safe(const char *str, const char **end, int *result)
{
	long long	value;
	size_t		i;
	int			is_negative;
	int			digit_found;

	is_negative = 0;
	i = 0;
	digit_found = 0;
	while (ft_strchr(" \t\n\b\f\v\r", str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			is_negative = 1;
	value = 0;
	while (ft_isdigit(str[i]))
	{
		digit_found = 1;
		value = value * 10 + str[i++] - '0';
		if ((!is_negative && value > INT_MAX) ||
			(is_negative && -value < INT_MIN))
			return (0);
	}
	*end = str + i;
	*result = (int)(value * (is_negative ? -1 : 1));
	return (digit_found ? 1 : 0);
}
