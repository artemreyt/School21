/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:02:19 by creicher          #+#    #+#             */
/*   Updated: 2020/01/04 03:02:30 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		specifier_handler(const char *format, va_list args_list) {
	return 0;
}


int		integer_spec_handler(const char *format, va_list args_list);
int		float_spec_handler(const char *format, va_list args_list);
