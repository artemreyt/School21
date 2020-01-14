/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_bases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:21:15 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/07 14:35:46 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "utils.h"

static void	print_few_times(char c, size_t n)
{
	while (n-- > 0)
		ft_putchar(c);
}

static void	print_alternative_form(char specifier)
{
	if (specifier == 'o')
		ft_putstr("0");
	else if (specifier == 'x')
		ft_putstr("0x");
	else if (specifier == 'X')
		ft_putstr("0X");
}

static void	print_left_or_right(const char *str, int width, int len, char fill_char,
						const flags_describer *describer)
{
	int	num_of_zeros;
	int	alternative_form;

	alternative_form = flag_is_found(HASH_FLAG, describer);
	if (describer->precision.found && describer->precision.value > ft_strlen(str))
		num_of_zeros = describer->precision.value - ft_strlen(str);
	else
		num_of_zeros = 0;
	if (width > len && !flag_is_found(MINUS_FLAG, describer))
		print_few_times(fill_char, (size_t)width - len);
	if (alternative_form && !(describer->specifier == 'o' && num_of_zeros > 0))
		print_alternative_form(describer->specifier);
	print_few_times('0', num_of_zeros);
	ft_putstr(str);
	if (width > len && flag_is_found(MINUS_FLAG, describer))
		print_few_times(fill_char, (size_t)width - len);
}

int			print_bases(const char *str, const flags_describer *describer)
{
	int		retv;
	int		width;
	int		len;
	char	fill_char;

	retv = 0;
	fill_char = ' ';
	if (flag_is_found(ZERO_FLAG, describer) &&
		!flag_is_found(MINUS_FLAG, describer) &&
		!describer->precision.found)
		fill_char = '0';
	width = describer->width;
	len = ft_strlen(str);
	if (describer->precision.found && describer->precision.value > len)
		len += describer->precision.value - len;
	if (flag_is_found(HASH_FLAG, describer))
	{
		if (describer->specifier == 'o' && len == ft_strlen(str))
			len++;
		else if (describer->specifier != 'o')
			len += 2;
	}
	retv = len + (width > len ? width - len : 0);
	print_left_or_right(str, width, len, fill_char, describer);
	return (retv);
}