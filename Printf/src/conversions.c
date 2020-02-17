/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:41:22 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 15:38:11 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversions.h"
#include "utils.h"
#include <stdio.h>
#include <inttypes.h>

char	*signed_conversion(va_list args_list, const t_fdescriber *describer)
{
	t_signed	number;
	char		*str;

	if (flag_is_found(z_FLAG, describer) || flag_is_found(j_FLAG, describer))
		number = (t_signed)(va_arg(args_list, intmax_t));
	else if (flag_is_found(ll_FLAG, describer))
		number = (t_signed)va_arg(args_list, long long);
	else if (flag_is_found(l_FLAG, describer))
		number = (t_signed)va_arg(args_list, long);
	else if (flag_is_found(h_FLAG, describer))
		number = (t_signed)((short)va_arg(args_list, int));
	else if (flag_is_found(hh_FLAG, describer))
		number = (t_signed)((char)va_arg(args_list, int));
	else
		number = (t_signed)va_arg(args_list, int);
	if (number == 0 && describer->precision.is_found
				&& describer->precision.value == 0)
		return (ft_strdup((flag_is_found(PLUS_FLAG, describer) ? "+" : "")));
	str = ft_signed_itoa(number, (flag_is_found(PLUS_FLAG, describer) ? 1 : 0));
	return (str);
}

char	*unsigned_conversion(va_list args_list,
							const t_fdescriber *describer)
{
	t_signed	number;

	if (flag_is_found(j_FLAG, describer) || describer->specifier == 'U')
		number = (t_unsigned)((uintmax_t)(va_arg(args_list, uintmax_t)));
	else if (flag_is_found(z_FLAG, describer))
		number = (t_unsigned)((size_t)(va_arg(args_list, size_t)));
	else if (flag_is_found(hh_FLAG, describer))
		number = (t_unsigned)((unsigned char)va_arg(args_list, unsigned int));
	else if (flag_is_found(h_FLAG, describer))
		number = (t_unsigned)((unsigned short)va_arg(args_list, unsigned int));
	else if (flag_is_found(l_FLAG, describer))
		number = (t_unsigned)va_arg(args_list, unsigned long);
	else if (flag_is_found(ll_FLAG, describer))
		number = (t_unsigned)va_arg(args_list, unsigned long long);
	else
		number = (t_unsigned)va_arg(args_list, unsigned int);
	if (number == 0 && describer->precision.is_found &&
		describer->precision.value == 0 &&
		!(describer->specifier == 'o' && flag_is_found(HASH_FLAG, describer)))
		return (ft_strdup(""));
	if (describer->specifier == 'u' || describer->specifier == 'U')
		return (ft_unsigned_itoa(number));
	return (get_str_base2(number, describer->specifier));
}

char	*float_conversion(va_list args_list, t_fdescriber *describer)
{
	t_float		number;
	char		*str;

	if (flag_is_found(L_FLAG, describer))
		number = va_arg(args_list, long double);
	else
		number = (t_float)va_arg(args_list, double);
	describer->precision.value = describer->precision.is_found ?
			describer->precision.value : DEFAULT_FLOAT_PRECISION;
	str = ft_dtoa(number, describer->precision.value);
	return (str);
}

char	*csp_conversion(va_list args_list, const t_fdescriber *describer)
{
	char	*str;
	char	character;

	if (describer->specifier == 'p')
		str = ft_itoa_base((t_unsigned)va_arg(args_list, void *), 16);
	else if (describer->specifier == 's')
	{
		str = va_arg(args_list, char *);
		if (!str)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
		if (describer->precision.is_found &&
					(size_t)describer->precision.value < ft_strlen(str))
			str[describer->precision.value] = '\0';
	}
	else if (describer->specifier == '%')
		str = ft_strdup("%");
	else
	{
		character = (char)va_arg(args_list, int);
		str = (char *)ft_memalloc(2);
		str[0] = character;
	}
	return (str);
}
