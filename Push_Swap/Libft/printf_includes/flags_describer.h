/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_describer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:15:49 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 16:25:26 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_DESCRIBER_H
# define FLAGS_DESCRIBER_H

# include <stdarg.h>
# include "libft.h"

# define DEFAULT_FLOAT_PRECISION 6

enum			e_flags
{
	hh_FLAG, h_FLAG,
	l_FLAG, ll_FLAG,
	L_FLAG, j_FLAG,
	z_FLAG, HASH_FLAG,
	ZERO_FLAG, PLUS_FLAG,
	MINUS_FLAG, STAR_FLAG,
	SPACE_FLAG, NILL_FLAG
};
typedef enum e_flags	t_flags;

struct			s_prec
{
	int	is_found;
	int	value;
};
typedef struct s_prec	t_precision;

struct			s_fdesc
{
	int			flags;
	int			width;
	t_precision	precision;
	char		specifier;
};
typedef struct s_fdesc	t_fdescriber;

t_fdescriber	*find_flags(t_fdescriber *describer,
							char **str, va_list args_list);
void			init_t_fdescriber(t_fdescriber *obj);
void			add_flag(t_flags flag, t_fdescriber *describer);
int				flag_is_found(t_flags flag, const t_fdescriber *describer);
void			destroy_t_fdescriber(t_fdescriber **obj);
int				check_num_conv_flags(const char *str, t_fdescriber *describer);
int				check_width_precision(const char *str, t_fdescriber *describer,
										va_list args_list);
int				check_not_conv_flags(const char *str, t_fdescriber *describer);

#endif
