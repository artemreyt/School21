/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_bases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:21:15 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 16:35:48 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "utils.h"
#include "print_format.h"

static int	get_alt_form_size(int hash_apply, char specifier)
{
	if (hash_apply)
	{
		if (specifier == 'o' || specifier == 'b')
			return (1);
		else
			return (2);
	}
	return (0);
}

static int	print_alternative_form(t_buffer *buffer, char specifier)
{
	if (specifier == 'o')
		buf_putstr(buffer, "0");
	else if (specifier == 'x' || specifier == 'p')
		buf_putstr(buffer, "0x");
	else if (specifier == 'b')
		buf_putstr(buffer, "b");
	else if (specifier == 'X')
		buf_putstr(buffer, "0X");
	return ('x' == ft_tolower(specifier) || specifier == 'p' ? 2 : 1);
}

static void	set_bool_flags(const t_fdescriber *describer, t_print_info *info)
{
	char	specifier;
	int		alt_form_size;
	int		len;

	len = info->len;
	specifier = describer->specifier;
	info->hash_apply = 0;
	if ((flag_is_found(HASH_FLAG, describer) && info->str[0] > '0')
		|| specifier == 'p')
		info->hash_apply = 1;
	alt_form_size = get_alt_form_size(info->hash_apply, specifier);
	info->num_of_zeros = 0;
	if (describer->precision.is_found)
	{
		if (describer->precision.value > len)
			info->num_of_zeros = describer->precision.value - len;
		if (specifier == 'o' && info->num_of_zeros > 0 && info->hash_apply)
			(info->num_of_zeros)--;
	}
	else if (!flag_is_found(MINUS_FLAG, describer)
			&& flag_is_found(ZERO_FLAG, describer) &&
		describer->width > len + alt_form_size)
		info->num_of_zeros = describer->width - (len + alt_form_size);
}

static int	print_prefix(t_buffer *buffer, const t_fdescriber *describer,
				t_print_info *info)
{
	int	width;
	int	alt_form_size;

	width = describer->width;
	alt_form_size = get_alt_form_size(info->hash_apply, describer->specifier);
	if (!flag_is_found(MINUS_FLAG, describer) &&
			width > info->len + alt_form_size + info->num_of_zeros)
	{
		print_few_times(buffer, ' ',
			width - info->len - alt_form_size - info->num_of_zeros);
		width -= width - (info->len + alt_form_size + info->num_of_zeros);
	}
	if (info->hash_apply)
		width -= print_alternative_form(buffer, describer->specifier);
	print_few_times(buffer, '0', info->num_of_zeros);
	width -= info->num_of_zeros;
	return (width);
}

int			print_bases(t_buffer *buffer, const char *str,
					const t_fdescriber *describer)
{
	t_print_info info;

	info.len = ft_strlen(str);
	info.str = str;
	set_bool_flags(describer, &info);
	info.width = print_prefix(buffer, describer, &info);
	buf_putstr(buffer, str);
	info.width -= info.len;
	if (flag_is_found(MINUS_FLAG, describer) && info.width > 0)
		print_few_times(buffer, ' ', info.width);
	return (1);
}
