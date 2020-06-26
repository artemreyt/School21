/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handlers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:29:28 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 15:33:35 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_HANDLERS_H
# define SPECIFIER_HANDLERS_H

# include <stdarg.h>
# include "t_buffer.h"
# include "ft_printf.h"
# include "extra.h"

int		specifier_handler(char **format, va_list args_list,
							t_buffer *buffer, t_extra *extra);

#endif
