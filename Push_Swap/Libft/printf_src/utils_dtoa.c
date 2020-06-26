/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:28:40 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 17:17:33 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdio.h>

/*
	** only positive floats
*/

t_float	ft_round(t_float number, int precision)
{
	t_float	fraction;
	t_float	new_fraction;
	t_float	digit;

	fraction = number - (t_float)((t_unsigned)(number));
	number = (t_float)((t_unsigned)(number));
	digit = 1;
	new_fraction = 0.0;
	while (precision >= 0)
	{
		new_fraction += (int)fraction * digit;
		fraction -= (int)fraction;
		fraction *= 10.0;
		if (precision == 0 && (int)fraction >= 5)
			new_fraction += digit;
		digit *= 0.1;
		precision--;
	}
	return (number + new_fraction);
}

char	*get_int_part(t_float number)
{
	char		*str;
	int			minus;
	char		*buf;

	minus = 0;
	if (number < 0.0 || is_minus_zero(number))
	{
		number = -number;
		minus = 1;
	}
	str = ft_unsigned_itoa((t_unsigned)number);
	if (minus)
	{
		buf = (char *)ft_memalloc(1 + ft_strlen(str) + 1);
		buf[0] = '-';
		ft_strcat(buf, str);
		ft_strdel(&str);
		str = buf;
	}
	return (str);
}

char	*get_fract_part(t_float number, int precision)
{
	char	*str;
	int		i;

	if (number < 0)
		number = -number;
	if (precision == 0)
		return (ft_strdup(""));
	str = (char *)ft_memalloc(1 + (size_t)precision + 1);
	str[0] = '.';
	number -= (t_float)((t_unsigned)number);
	i = 1;
	while (precision-- > 0)
	{
		number *= 10.0;
		str[i] = (int)number + '0';
		number -= (int)number;
		if (precision == 0 && str[i] < '9' && number * 10.0 >= 5)
			str[i]++;
		i++;
	}
	return (str);
}

char	*ft_dtoa(t_float number, int precision)
{
	char	*str;
	int		minus;

	if ((str = check_zero_inf_nan(number, precision)))
		return (str);
	minus = 0;
	if (number < 0.0)
	{
		number = -number;
		minus = 1;
	}
	number = ft_round(number, precision);
	str = ft_str_round(number, precision, minus);
	return (str);
}
