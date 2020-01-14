/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:35:31 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/15 02:49:06 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"
#include "conversions.h"
#include "utils.h"

static void	print_few_times(char c, size_t n)
{
	while (n-- > 0)
		ft_putchar(c);
}

int		print_float(const char *str, const flags_describer *describer)
{
	size_t	len;
	int		hash_flag;

	hash_flag = flag_is_found(HASH_FLAG, describer)
				&& describer->precision.value == 0;
	len = ft_strlen(str);
	if (flag_is_found(SPACE_FLAG, describer) && str[0] != '-')
	{
		len++;
		ft_putchar(' ');
	}
	if (hash_flag)
		len++;
	if (describer->width > len && !flag_is_found(MINUS_FLAG, describer))
		print_few_times(' ', describer->width - len);
	ft_putstr(str);
	if (hash_flag)
		ft_putchar('.');
	if (describer->width > len && flag_is_found(MINUS_FLAG, describer))
		print_few_times(' ', describer->width - len);
	return (len);
}
