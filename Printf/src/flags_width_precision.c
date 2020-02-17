/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:38:48 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 16:35:23 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"

static int	check_star_width(const char *str, t_fdescriber *describer,
								va_list args_list)
{
	int	width;

	if (*str == '*')
	{
		width = va_arg(args_list, int);
		if (width < 0)
		{
			describer->width = -width;
			add_flag(MINUS_FLAG, describer);
		}
		else
			describer->width = width;
		return (1);
	}
	return (0);
}

static int	check_star_precision(const char *str, t_fdescriber *describer,
								va_list args_list)
{
	int precision;

	if (*str == '*')
	{
		precision = va_arg(args_list, int);
		if (precision >= 0)
		{
			describer->precision.value = precision;
			describer->precision.is_found = 1;
		}
		return (1);
	}
	return (0);
}

int			do_check_width_precision(const char *str, t_fdescriber *describer,
									va_list args_list)
{
	int i;

	i = 0;
	if (check_star_width(str, describer, args_list))
		i++;
	if (ft_isdigit(str[i]) && (describer->width = ft_atoi(str + i)))
		while (ft_isdigit(str[i]))
			i++;
	if (str[i] == '.')
	{
		i++;
		if (check_star_precision(str + i, describer, args_list))
			i++;
		else
		{
			describer->precision.value = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
			describer->precision.is_found = 1;
		}
	}
	return (i);
}

int			check_width_precision(const char *str, t_fdescriber *describer,
									va_list args_list)
{
	int	count;
	int	val;

	count = 0;
	while (str[count] &&
		(val = do_check_width_precision(str + count, describer, args_list)) > 0)
		count += val;
	return (count);
}
