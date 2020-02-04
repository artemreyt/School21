/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:02:19 by creicher          #+#    #+#             */
/*   Updated: 2020/02/05 00:56:33 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "flags_describer.h"
#include "print_format.h"
#include "utils.h"
#include <stdio.h>

static int		integer_spec_handler(va_list args_list, const flags_describer *describer)
{
	char	*str;
	int		len;
	char	specifier;

	specifier = describer->specifier;
	if (specifier == 'd' || specifier == 'i')
		str = signed_conversion(args_list, describer);
	else
		str = unsigned_conversion(args_list, describer);
	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		len = print_decimal(str, describer);
	else
		len = print_bases(str, describer);
	free(str);
	return (len);
}

static int		float_spec_handler(va_list args_list, const flags_describer *describer)
{
	char	*str;
	int		len;

	str = float_conversion(args_list, (flags_describer *) describer);
	len = print_float(str, describer);
	free(str);
	return (len);
}
static int		csp_spec_handler(va_list args_list, const flags_describer *describer) 
{
	int		len;
	char	specifier;
	char	*str;
	char	character;

	specifier = describer->specifier;
	if (specifier == 'p')
		str = ft_itoa_base((t_unsigned)va_arg(args_list, void *), 16);
	else if (specifier == 's')
	{
		str = va_arg(args_list, char *);
		if (!str)
			str = ft_strdup("(null)");
		else
		{
			str = ft_strdup(str);
			if (describer->precision.found && describer->precision.value < ft_strlen(str))
				str[describer->precision.value] = '\0';
		}
	}
	else
	{
		if (specifier == '%')
			character = '%';
		else
			character = (char)va_arg(args_list, int);
		str = (char *)ft_memalloc(2);
		str[0] = character;
	}
	len = print_csp(str, describer);
	free(str);
	return (len);
}
static int		unknown_spec_handler(flags_describer *describer)
{
	return (0);
}


int		specifier_handler(char **format, va_list args_list) {
	flags_describer		*describer;
	int					retv;
	
	describer = find_flags(format);
	if (ft_strchr(INTEGER_SPECIFIERS, describer->specifier))
		retv = integer_spec_handler(args_list, describer);
	else if (ft_strchr(FLOAT_SPECIFIERS, describer->specifier))
		retv = float_spec_handler(args_list, (flags_describer*) describer);
	else if (ft_strchr(CSP_SPECIFIERS, describer->specifier))
		retv = csp_spec_handler(args_list, describer);
	else
		retv = unknown_spec_handler(describer);
	destroy_flags_describer(&describer);
	if (**format)
		(*format)++;
	return (retv);
}

