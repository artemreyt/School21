/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:31:34 by creicher          #+#    #+#             */
/*   Updated: 2020/01/07 02:37:37 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "flags_describer.h"
# include "conversions.h"

int		flag_is_found(e_flags flag, const flags_describer *describer);
char	*ft_signed_itoa(t_signed n, int plus);
char	*ft_unsigned_itoa(t_unsigned n);
char	*get_str_base2(t_unsigned number, char specifier);

#endif
