/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:21:06 by creicher          #+#    #+#             */
/*   Updated: 2019/12/30 22:10:22 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...) {
	va_list	args_list;
	int		retv;
	const char	*end;
	int		buf1;
	int		buf2;

	va_start(args_list, format);
	end = format;
	retv = 0;
	while (*end) {
		if (*end == '%') {
			if ((buf1 = write(1, format, (size_t)(end - format))) < 0 ||
				(buf2 = specifier_handler(end++, args_list)) < 0) {
				va_end(args_list);
				return -1;
			}
			retv += buf1 + buf2;
			end += buf2;
			format = end;
		}
		else
			end++;
	}
	ft_putstr(format);
	va_end(args_list);
	return retv;
}
