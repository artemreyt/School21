/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:41:55 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/16 01:55:25 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_CONVERSIONS_H
# define ALL_CONVERSIONS_H

# include "flags_describer.h"
# include <limits.h>

typedef long long	t_signed;
typedef uintmax_t	t_unsigned;
typedef long double	t_float;

char	*signed_conversion(va_list args_list, const flags_describer *describer);
char	*unsigned_conversion(va_list args_list, const flags_describer *describer);
char	*float_conversion(va_list args_list, flags_describer *describer);

#endif
