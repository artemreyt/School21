    
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:26:39 by creicher          #+#    #+#             */
/*   Updated: 2020/01/04 02:43:12 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "flags_describer.h"
# include "specifier_handlers.h"

# define INTEGER_SPECIFIERS	"diouxX"
# define FLOAT_SPECIFIERS	"fFeEgG"
# define CSP_SPECIFIERS		"csp%"

int		ft_printf(const char *format, ...);

#endif
