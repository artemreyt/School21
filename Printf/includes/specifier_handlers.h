/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handlers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:29:28 by creicher          #+#    #+#             */
/*   Updated: 2020/01/06 16:41:26 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPECIFIER_HANDLERS_H
# define SPECIFIER_HANDLERS_H

# include <stdarg.h>

int		specifier_handler(char **format, va_list args_list);

#endif
