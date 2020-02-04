/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:41:22 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/17 17:19:40 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversions.h"
#include "utils.h"
#include <stdio.h>

char	*signed_conversion(va_list args_list, const flags_describer *describer)
{
	t_signed	number;
	char		*str;

	if (flag_is_found(hh_FLAG, describer))
		number = (t_signed)((char)va_arg(args_list, int));
	else if (flag_is_found(h_FLAG, describer))
		number = (t_signed)((short)va_arg(args_list, int));
	else if (flag_is_found(l_FLAG, describer))
		number = (t_signed)va_arg(args_list, long);
	else if (flag_is_found(ll_FLAG, describer))
		number = (t_signed)va_arg(args_list, long long);
	else 
		number = (t_signed)va_arg(args_list, int);
	if (number == 0 && describer->precision.found && describer->precision.value == 0)
		return (ft_strdup(""));
	str = ft_signed_itoa(number, (flag_is_found(PLUS_FLAG, describer) ? 1 : 0));
	return (str);
}

char	*unsigned_conversion(va_list args_list, const flags_describer *describer)
{
	t_signed	number;
	char		*str;

	if (flag_is_found(hh_FLAG, describer))
		number = (t_unsigned)((unsigned char)va_arg(args_list, unsigned int));
	else if (flag_is_found(h_FLAG, describer))
		number = (t_unsigned)((unsigned short)va_arg(args_list, unsigned int));
	else if (flag_is_found(l_FLAG, describer))
		number = (t_unsigned)va_arg(args_list, unsigned long);
	else if (flag_is_found(ll_FLAG, describer))
		number = (t_unsigned)va_arg(args_list, unsigned long long);
	else 
		number = (t_unsigned)va_arg(args_list, unsigned int);
	if (number == 0 && describer->precision.found &&
		describer->precision.value == 0 &&
		!(describer->specifier == 'o' && flag_is_found(HASH_FLAG, describer)))
		return (ft_strdup(""));
	if (describer->specifier == 'u')
		str = ft_unsigned_itoa(number);
	else
		str = get_str_base2(number, describer->specifier);
	return (str);
}

char	*float_conversion(va_list args_list, flags_describer *describer)
{
	t_float		number;
	char		*str;

	if (flag_is_found(L_FLAG, describer))
		number = va_arg(args_list, long double);
	else
		number = (t_float)va_arg(args_list, double);
	describer->precision.value = describer->precision.found ?
			describer->precision.value : DEFAULT_FLOAT_PRECISION;
	str = ft_dtoa(number, describer->precision.value);
	return (str);
}

char	*csp_conversion(va_list args_list, const flags_describer *describer)
{
	/*
		pass
	*/
}
