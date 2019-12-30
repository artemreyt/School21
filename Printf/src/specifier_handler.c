/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:02:19 by creicher          #+#    #+#             */
/*   Updated: 2019/12/30 22:06:34 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		specifier_handler(const char *format, va_list args_list) {
	
}


int		integer_spec_handler(const char *format, va_list args_list);
int		float_spec_handler(const char *format, va_list args_list);
