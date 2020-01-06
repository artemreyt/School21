/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:21:06 by creicher          #+#    #+#             */
/*   Updated: 2020/01/06 16:44:20 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *restrict format, ...) {
	va_list		args_list;
	int			retv;
	char		*end;
	int			buf2;

	va_start(args_list, format);
	end = (char *)format;
	retv = 0;
	while (*end) {
		if (*end == '%') {
			//printf("\nFOUND %%\n");
			end++;
			if ((buf2 = specifier_handler(&end, args_list)) < 0) {
				va_end(args_list);
				return -1;
			}
			retv += buf2;
		}
		else
		{
			ft_putchar(*end);
			retv++;
			end++;
		}
	}
	va_end(args_list);
	return retv;
}
