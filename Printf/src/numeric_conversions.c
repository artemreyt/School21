/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:41:22 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/06 22:22:55 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "all_conversions.h"
#include "utils.h"
#include <stdio.h>

char	*di_conversion(va_list args_list, const flags_describer *describer)
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
	str = ft_signed_itoa(number, (flag_is_found(PLUS_FLAG, describer) ? 1 : 0));
	return (str);
}

char	*ouxX_conversion(const char specifier, va_list args_list,
						const flags_describer *describer)
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
	if (specifier == 'u')
		str = ft_unsigned_itoa(number);
	else
		str = str_base2(number, flag_is_found(HASH_FLAG, describer));
	return (str);
}

