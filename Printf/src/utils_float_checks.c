/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 00:46:04 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 17:22:02 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

inline int		is_nan(t_float x)
{
	return (x != x);
}

inline int		is_pos_inf(t_float x)
{
	return (x == INFINITY);
}

inline int		is_minus_inf(t_float x)
{
	return (x == -INFINITY);
}

inline int		is_minus_zero(t_float x)
{
	return (is_minus_inf(1.0 / x));
}

/*
	** Return values:
	** NULL - if no zero, inf or nan... string with zero, inf, or nan...
*/

char			*check_zero_inf_nan(t_float number, int precision)
{
	char	*str;
	char	buf[5];
	size_t	len;

	buf[0] = '\0';
	if (number == 0.0)
	{
		len = 1;
		len += (is_minus_zero(number) ? 1 : 0);
		str = (char *)ft_memalloc(len + 1);
		ft_strcpy(str, (is_minus_zero(number) ? "-0" : "0"));
		if (precision > 0)
		{
			str = append_few_letters(str, '.', 1);
			str = append_few_letters(str, '0', precision);
		}
		return (str);
	}
	if (is_nan(number))
		ft_strcpy(buf, NAN_STR);
	else if (is_pos_inf(number))
		ft_strcpy(buf, INF_STR);
	else if (is_minus_inf(number))
		ft_strcpy(buf, MINUS_INF_STR);
	return (buf[0] == '\0' ? NULL : ft_strdup(buf));
}
