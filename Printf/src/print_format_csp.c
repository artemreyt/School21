/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_csp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:57:01 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/17 17:04:09 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"
#include "conversions.h"
#include "utils.h"
#include "print_format.h"

int		print_csp(char *str, const flags_describer *describer)
{
	int		len;
	int		width;
	char	specifier;

	specifier = describer->specifier;
	if (specifier == 'p')
		return (print_bases(str, describer));
	width = describer->width;
	len = ft_strlen(str);
	if (specifier == 'c' && str[0] == 0)
		len++;
	// if (specifier == 'p')
	// 	len += 2;
	if (describer->width > len && !flag_is_found(MINUS_FLAG, describer))
		print_few_times(' ', describer->width - len);
	// if (specifier == 'p')
	// 	ft_putstr("0x");
	if (specifier == 'c' && str[0] == 0)
		ft_putchar('\0');
	// else if (specifier == 'p' && describer->precision.found 
	// 			&& !describer->precision.value && str[0] == '0')
	// {
	// 	len--;
	// 	str[0] = '\0';
	// }
	ft_putstr(str);
	if (describer->width > len && flag_is_found(MINUS_FLAG, describer))
		print_few_times(' ', describer->width - len);
	return (len + ((width > len) ? width - len : 0));
}
