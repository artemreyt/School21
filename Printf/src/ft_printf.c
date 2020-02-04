/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:21:06 by creicher          #+#    #+#             */
/*   Updated: 2020/01/17 16:42:27 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...) {
	va_list		args_list;
	int			retv;
	char		*end;
	int			buf;

	va_start(args_list, format);
	end = (char *)format;
	retv = 0;
	while (*end) {
		if (*end == '%') {
			write(1, format, (size_t)(end++ - format));
			if ((buf = specifier_handler(&end, args_list)) < 0) {
				va_end(args_list);
				return -1;
			}
			format = end;
			retv += buf;
		}
		else
		{
			retv++;
			end++;
		}
	}
	write(1, format, end - format);
	va_end(args_list);
	return retv;
}
