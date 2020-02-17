/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:35:31 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 16:38:14 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"
#include "conversions.h"
#include "utils.h"
#include "print_format.h"

static void		set_bool_flags(const t_fdescriber *describer,
								t_print_info *info)
{
	info->hash_apply = flag_is_found(HASH_FLAG, describer) &&
		describer->precision.is_found && !describer->precision.value;
	info->plus_found = flag_is_found(PLUS_FLAG, describer) &&
						info->str[0] != '-';
	info->fill_char = !flag_is_found(MINUS_FLAG, describer) &&
				flag_is_found(ZERO_FLAG, describer) ? '0' : ' ';
}

static int		make_space(t_buffer *buffer, int is_need)
{
	if (is_need)
	{
		buf_putchar(buffer, ' ');
		return (1);
	}
	return (0);
}

int				print_float(t_buffer *buffer, const char *str,
							const t_fdescriber *describer)
{
	t_print_info info;

	info.width = describer->width;
	info.len = (int)ft_strlen(str);
	info.str = str;
	set_bool_flags(describer, &info);
	info.width -= make_space(buffer, !info.plus_found &&
		str[0] != '-' && flag_is_found(SPACE_FLAG, describer));
	info.width -= info.plus_found + info.hash_apply;
	if (info.fill_char == '0' && (info.plus_found || str[0] == '-'))
		buf_putchar(buffer, info.plus_found ? '+' : '-');
	if (!flag_is_found(MINUS_FLAG, describer) && info.width > info.len)
		print_few_times(buffer, info.fill_char, info.width - info.len);
	if (info.fill_char == ' ' && (info.plus_found || str[0] == '-'))
		buf_putchar(buffer, info.plus_found ? '+' : '-');
	buf_putstr(buffer, str + (str[0] == '-' ? 1 : 0));
	info.width -= info.len;
	if (info.hash_apply)
		buf_putchar(buffer, '.');
	if (flag_is_found(MINUS_FLAG, describer) && info.width > 0)
		print_few_times(buffer, info.fill_char, info.width);
	return (1);
}
