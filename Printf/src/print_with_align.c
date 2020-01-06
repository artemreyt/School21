/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_align.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:27:58 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/06 21:41:33 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

static void	print_few_times(char c, size_t n)
{
	while (n-- > 0)
		ft_putchar(c);
}

static void	print_left_or_right(const char *str, int width, int len, char fill_char,
						const flags_describer *describer)
{
	int	space_flag_is_found;

	space_flag_is_found = flag_is_found(SPACE_FLAG, describer);
	if (width > len && flag_is_found(MINUS_FLAG, describer))
	{
		if (space_flag_is_found)
			ft_putchar(' ');
		ft_putstr(str);
		print_few_times(fill_char, (size_t)width - len);
	}
	else
	{
		if (width > len)
			print_few_times(fill_char, (size_t)width - len);
		if (space_flag_is_found)
			ft_putchar(' ');
		ft_putstr(str);
	}
}

int			print_number_with_align(const char *str, const flags_describer *describer)
{
	int		retv;
	int		width;
	int		len;
	char	fill_char;

	fill_char = ' ';
	if (flag_is_found(ZERO_FLAG, describer) &&
		!flag_is_found(MINUS_FLAG, describer))
		fill_char = '0';
	width = describer->width;
	len = ft_strlen(str);
	if (flag_is_found(SPACE_FLAG, describer))
		len++;
	retv = len + (width > len ? width - len : 0);
	print_left_or_right(str, width, len, fill_char, describer);
	return (retv);
}
