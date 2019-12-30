/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:26:39 by creicher          #+#    #+#             */
/*   Updated: 2019/12/30 21:31:25 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define INTEGER_SPECIFIERS "diouxX"
# define FLOAT_SPECIFIERS "fFeEgG"

int		ft_printf(const char * restrict format, ...);

#endif
