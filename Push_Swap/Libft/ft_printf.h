/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:26:39 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 15:33:30 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "flags_describer.h"
# include "specifier_handlers.h"
# include "visuals.h"

# define INTEGER_SPECIFIERS	"diouUxXb"
# define FLOAT_SPECIFIERS	"fFeEgG"
# define CSP_SPECIFIERS		"csp%"

int		ft_printf_fd(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
