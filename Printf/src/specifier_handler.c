/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:02:19 by creicher          #+#    #+#             */
/*   Updated: 2020/01/06 21:26:21 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "flags_handler.h"
#include "utils.h"
#include <stdio.h>

static int		integer_spec_handler(const char c, va_list args_list, const flags_describer *describer)
{
	char	*str;
	int		len;
	
	// printf("IN INTEGER_SPEC_HANDLER\n");
	if (c == 'd' || c == 'i')
		str = di_conversion(args_list, describer);
	else
		str = ouxX_conversion(c, args_list, describer);
	len = print_number_with_align(str, describer);
	free(str);
	return (len);
}

static int		float_spec_handler(const char c, va_list args_list, const flags_describer *describer)
{
	return (0);
}
static int		csp_spec_handler(const char c, va_list args_list, const flags_describer *describer) 
{
	return (0);
}
static int		unknown_spec_handler(const char c, flags_describer *describer)
{
	return (0);
}


int		specifier_handler(char **format, va_list args_list) {
	flags_describer		*describer;
	int					retv;
	
	// printf("IN SPEC_HANDLER\n");
	describer = find_flags(format);
	if (ft_strchr(INTEGER_SPECIFIERS, **format))
		retv = integer_spec_handler(**format, args_list, describer);
	else if (ft_strchr(FLOAT_SPECIFIERS, **format))
		retv = float_spec_handler(**format, args_list, describer);
	else if (ft_strchr(CSP_SPECIFIERS, **format))
		retv = csp_spec_handler(**format, args_list, describer);
	else
		retv = unknown_spec_handler(**format, describer);
	destroy_flags_describer(&describer);
	(*format)++;
	return (retv);
}

