/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_conversions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:41:55 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/06 21:50:51 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_CONVERSIONS_H
# define ALL_CONVERSIONS_H

# include "flags_handler.h"

typedef long long	t_signed;
typedef size_t		t_unsigned;

char	*di_conversion(va_list args_list, const flags_describer *describer);
char	*ouxX_conversion(const char c, va_list args_list, const flags_describer *describer);

#endif
