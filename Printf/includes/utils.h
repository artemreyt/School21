/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:31:34 by creicher          #+#    #+#             */
/*   Updated: 2020/01/14 03:11:23 by artemstarsh      ###   ########.fr       */
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
char	*append_few_letters(char *str, char c, size_t n);

int		check_nan(t_float number);
int		check_inf(t_float number);

# define IS_NAN(x) (x != x)
# define IS_POS_INF(x) (x == (long double) 1.0 / 0)
# define IS_MINUS_INF(x) (x == (long double) -1.0 / 0)
# define IS_MINUS_ZERO(x) (IS_MINUS_INF(1.0 / x))

# define NAN_STR		"nan"
# define INF_STR		"inf"
# define MINUS_INF_STR	"-inf"

char	*ft_dtoa(t_float number, int precision);

#endif
