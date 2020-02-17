/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:02:19 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 16:48:54 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "flags_describer.h"
#include "print_format.h"
#include "utils.h"
#include "visuals.h"
#include <stdio.h>

static int		integer_spec_handler(t_buffer *buffer, va_list args_list,
					const t_fdescriber *describer)
{
	char	*str;
	int		ok;
	char	specifier;

	specifier = describer->specifier;
	if (specifier == 'd' || specifier == 'i')
		str = signed_conversion(args_list, describer);
	else
		str = unsigned_conversion(args_list, describer);
	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		ok = print_decimal(buffer, str, describer);
	else
		ok = print_bases(buffer, str, describer);
	free(str);
	return (ok);
}

static int		float_spec_handler(t_buffer *buffer,
							va_list args_list, const t_fdescriber *describer)
{
	char	*str;
	int		len;

	str = float_conversion(args_list, (t_fdescriber *)describer);
	len = print_float(buffer, str, describer);
	free(str);
	return (len);
}

static int		csp_spec_handler(t_buffer *buffer,
						va_list args_list, const t_fdescriber *describer)
{
	char	*str;
	int		len;

	str = csp_conversion(args_list, (t_fdescriber *)describer);
	len = print_csp(buffer, str, describer);
	free(str);
	return (len);
}

int				specifier_handler(char **format, va_list args_list,
									t_buffer *buffer, t_extra *extra)
{
	t_fdescriber		describer;
	int					ok;

	if (**format == VISUAL_SPEC_OPEN)
		return (visuals_handler(format, args_list, buffer, extra));
	ok = 1;
	init_t_fdescriber(&describer);
	find_flags(&describer, format, args_list);
	if (ft_strchr(INTEGER_SPECIFIERS, describer.specifier))
		ok = integer_spec_handler(buffer, args_list, &describer);
	else if (ft_strchr(FLOAT_SPECIFIERS, describer.specifier))
		ok = float_spec_handler(buffer, args_list,
								(t_fdescriber*)&describer);
	else if (ft_strchr(CSP_SPECIFIERS, describer.specifier))
		ok = csp_spec_handler(buffer, args_list, &describer);
	else
	{
		if (describer.specifier != '@')
			buf_putchar(buffer, describer.specifier);
		ok = 1;
	}
	return (ok);
}
