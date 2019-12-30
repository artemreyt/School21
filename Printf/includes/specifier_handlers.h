/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handlers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:29:28 by creicher          #+#    #+#             */
/*   Updated: 2019/12/30 21:30:53 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPECIFIER_HANDLERS_H
# define SPECIFIER_HANDLERS_H

# include <stdarg.h>

int		specifier_handler(const char *format, va_list args_list);
int		integer_spec_handler(const char *format, va_list args_list);
int		float_spec_handler(const char *format, va_list args_list);

#endif
