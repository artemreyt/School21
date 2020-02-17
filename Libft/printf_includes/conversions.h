/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:41:55 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 15:33:24 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_CONVERSIONS_H
# define ALL_CONVERSIONS_H

# include "flags_describer.h"
# include <inttypes.h>

typedef long long	t_signed;
typedef uintmax_t	t_unsigned;
typedef long double	t_float;

char	*signed_conversion(va_list args_list, const t_fdescriber *describer);
char	*unsigned_conversion(va_list args_list,
							const t_fdescriber *describer);
char	*float_conversion(va_list args_list, t_fdescriber *describer);
char	*csp_conversion(va_list args_list, const t_fdescriber *describer);

#endif
