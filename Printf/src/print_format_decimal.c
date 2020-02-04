/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:27:58 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/16 02:23:07 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"


static void	print_left_or_right(const char *str, int width, int len, char fill_char,
						const flags_describer *describer)
{
	int		space_flag_is_found;
	int		num_of_zeros;

	if (describer->precision.found && describer->precision.value >= ft_strlen(str))
	{
		num_of_zeros = describer->precision.value - ft_strlen(str);
		if (str[0] == '-' || str[0] == '+')
			num_of_zeros++;
	}
	else
		num_of_zeros = 0;
	space_flag_is_found = flag_is_found(SPACE_FLAG, describer) &&
			describer->specifier != 'u' && str[0] != '-' && str[0] != '+';
	if (space_flag_is_found)
		ft_putchar(' ');
	if (fill_char == '0' && (str[0] == '+' || str[0] == '-'))
		ft_putchar(*(str++));
	if (width > len && !flag_is_found(MINUS_FLAG, describer))
		print_few_times(fill_char, (size_t)width - len);
	if (fill_char == ' ' && (str[0] == '+' || str[0] == '-'))
		ft_putchar(*(str++));
	print_few_times('0', num_of_zeros);
	ft_putstr(str);
	if (width > len && flag_is_found(MINUS_FLAG, describer))
		print_few_times(fill_char, (size_t)width - len);
}

int			print_decimal(const char *str, const flags_describer *describer)
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
	if (flag_is_found(SPACE_FLAG, describer) && describer->specifier != 'u' &&
			str[0] != '-' && str[0] != '+')
		len++;
	if (describer->precision.found && describer->precision.value >= ft_strlen(str) &&
			(str[0] == '-' || str[0] == '+'))
		len++;
	retv = len + (width > len ? width - len : 0);
	print_left_or_right(str, width, len, fill_char, describer);
	return (retv);
}
