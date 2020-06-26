/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:27:58 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 16:36:54 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "t_buffer.h"
#include "print_format.h"

static void	print_prefix(t_buffer *buffer, const t_fdescriber *describer,
								t_print_info *info)
{
	int	space_flag_is_found;

	space_flag_is_found = flag_is_found(SPACE_FLAG, describer) &&
		ft_tolower(describer->specifier) != 'u' &&
		info->str[0] != '-' && info->str[0] != '+';
	if (space_flag_is_found)
		buf_putchar(buffer, ' ');
	if (info->fill_char == '0' && (info->str[0] == '+' || info->str[0] == '-'))
		buf_putchar(buffer, *(info->str++));
	if (info->width > info->len && !flag_is_found(MINUS_FLAG, describer))
		print_few_times(buffer, info->fill_char,
						(size_t)info->width - info->len);
	if (info->fill_char == ' ' && (info->str[0] == '+' || info->str[0] == '-'))
		buf_putchar(buffer, *(info->str++));
	print_few_times(buffer, '0', info->num_of_zeros);
}

static void	print_left_or_right(t_buffer *buffer, const t_fdescriber *describer,
								t_print_info *info)
{
	size_t len;

	len = ft_strlen(info->str);
	if (describer->precision.is_found &&
			(size_t)describer->precision.value >= len)
	{
		info->num_of_zeros = describer->precision.value - len;
		if (info->str[0] == '-' || info->str[0] == '+')
			info->num_of_zeros++;
	}
	else
		info->num_of_zeros = 0;
	print_prefix(buffer, describer, info);
	buf_putstr(buffer, info->str);
	if (info->width > info->len && flag_is_found(MINUS_FLAG, describer))
		print_few_times(buffer, info->fill_char,
						(size_t)info->width - info->len);
}

int			print_decimal(t_buffer *buffer, const char *str,
							const t_fdescriber *describer)
{
	t_print_info	info;
	size_t			len;

	len = ft_strlen(str);
	info.fill_char = ' ';
	if (flag_is_found(ZERO_FLAG, describer) &&
		!flag_is_found(MINUS_FLAG, describer) &&
		!describer->precision.is_found)
		info.fill_char = '0';
	info.str = str;
	info.width = describer->width;
	info.len = len;
	if (describer->precision.is_found && describer->precision.value > info.len)
		info.len += describer->precision.value - info.len;
	if (flag_is_found(SPACE_FLAG, describer) &&
		ft_tolower(describer->specifier) != 'u' &&
			str[0] != '-' && str[0] != '+')
		info.len++;
	if (describer->precision.is_found &&
			(size_t)describer->precision.value >= len &&
			(str[0] == '-' || str[0] == '+'))
		info.len++;
	print_left_or_right(buffer, describer, &info);
	return (1);
}
