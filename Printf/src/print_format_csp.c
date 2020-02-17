/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_csp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:57:01 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 16:36:06 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"
#include "conversions.h"
#include "utils.h"
#include "print_format.h"

static int	print_p(t_buffer *buffer,
			char *str, const t_fdescriber *describer)
{
	if (describer->precision.is_found && describer->precision.value == 0
		&& str[0] == '0')
		str[0] = '\0';
	return (print_bases(buffer, str, describer));
}

int			print_csp(t_buffer *buffer,
					char *str, const t_fdescriber *describer)
{
	t_print_info info;

	if (describer->specifier == 'p')
		return (print_p(buffer, str, describer));
	info.len = ft_strlen(str);
	info.fill_char = flag_is_found(ZERO_FLAG, describer) &&
		!flag_is_found(MINUS_FLAG, describer) ? '0' : ' ';
	if (describer->specifier == 'c' && str[0] == 0)
		info.len++;
	if (describer->width > info.len && !flag_is_found(MINUS_FLAG, describer))
		print_few_times(buffer, info.fill_char, describer->width - info.len);
	if (describer->specifier == 'c' && str[0] == 0)
		buf_putchar(buffer, '\0');
	buf_putstr(buffer, str);
	if (describer->width > info.len && flag_is_found(MINUS_FLAG, describer))
		print_few_times(buffer, info.fill_char, describer->width - info.len);
	return (1);
}
