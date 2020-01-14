/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:28:40 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/15 02:38:57 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdio.h>

t_float	ft_round(t_float number, int precision)
{
	t_float	fraction;
	t_float	append;
	t_float	new_fraction;
	t_float	digit;

	if (number < 0)
		fraction = -(number + (t_float)((t_unsigned)(-number)));
	else
		fraction = number - (t_float)((t_unsigned)(number));
	number += (number >= 0) ? -fraction : fraction;
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
	return (number + ((number >= 0) ? new_fraction : -new_fraction));
}

/*
	** return values:
	** NULL - if no zero, inf or nan...
	** string with zero, inf, or nan...
*/
char	*check_zero_inf_nan(t_float number, int precision)
{
	char	*str;
	char	buf[5];
	size_t	len;

	if (number == 0.0)
	{
		len = 2;
		if (IS_MINUS_INF(number))
			len++;
		str = (char *)ft_memalloc(len + 1);
		ft_strcpy(str, (IS_MINUS_INF(number) ? "-0" : "0"));
		if (precision > 0)
		{
			append_few_letters(str, '.', 1);
			append_few_letters(str, '0', precision);
		}
		return (str);
	}
	if (IS_NAN(number))
		ft_strcpy(buf, NAN_STR);
	else if (IS_POS_INF(number))
		ft_strcpy(buf, INF_STR);
	else if (IS_MINUS_INF(number))
		ft_strcpy(buf, MINUS_INF_STR);
	return (buf[0] == '\0' ? NULL : ft_strdup(buf));
}

char	*get_int_part(t_float number)
{
	char		*str;
	int			minus;
	char		*buf;

	minus = 0;
	if (number < 0)
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
		free(str);
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
	char	*int_part;
	char	*fract_part;
	size_t	len;

	if ((str = check_zero_inf_nan(number, precision)))
		return (str);
	//if (precision != DEFAULT_FLOAT_PRECISION)
		number = ft_round(number, precision);
	int_part = get_int_part(number);
	fract_part = get_fract_part(number, precision);
	len = ft_strlen(int_part) + ft_strlen(fract_part);
	str = (char *)ft_memalloc(len + 1);
	ft_strcpy(str, int_part);
	ft_strcat(str, fract_part);
	free(int_part);
	free(fract_part);
	return (str);
}
