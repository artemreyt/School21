/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:31:34 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 15:33:51 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "flags_describer.h"
# include "conversions.h"
# include "t_buffer.h"

char	*ft_signed_itoa(t_signed n, int plus);
char	*ft_unsigned_itoa(t_unsigned n);
char	*ft_itoa_base(t_unsigned number, int base);
char	*get_str_base2(t_unsigned number, char specifier);
char	*append_few_letters(char *str, char c, size_t n);
void	print_few_times(t_buffer *buffer, char c, size_t n);
char	*get_fract_part(t_float number, int precision);
char	*get_int_part(t_float number);
char	*ft_dtoa(t_float number, int precision);
char	*ft_str_round(t_float number, int precision, int minus);
void	lst_content_simple_free(void *ptr, size_t size);

# define NAN_STR		"nan"
# define INF_STR		"inf"
# define MINUS_INF_STR	"-inf"

char	*ft_dtoa(t_float number, int precision);
char	*check_zero_inf_nan(t_float number, int precision);
int		is_nan(t_float x);
int		is_pos_inf(t_float x);
int		is_minus_inf(t_float x);
int		is_minus_zero(t_float x);

#endif
