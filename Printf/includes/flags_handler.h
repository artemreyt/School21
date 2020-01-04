/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:15:49 by creicher          #+#    #+#             */
/*   Updated: 2020/01/04 03:24:50 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_HANDLER_H
# define FLAGS_HANDLER_H

# include <stdarg.h>
# include "libft.h"

# define DEFAULT_FLOAT_PRECISION 6

enum e_flags {
	hh_FLAG, h_FLAG,
	l_FLAG, ll_FLAG,
	L_FLAG, HASH_FLAG,
	ZERO_FLAG, PLUS_FLAG,
	MINUS_FLAG, STAR_FLAG
};
typedef			enum e_flags e_flags;

struct			s_precision {
	int	found;
	int	value;
};
typedef			struct s_precision s_precision;

struct			s_flags_describer {
	t_list		*flags;
	int			width;
	s_precision	precision;
};
typedef			struct s_flags_describer flags_describer;

flags_describer *find_flags(char **str);
flags_describer *create_flags_describer();
void			destroy_flags_describer(flags_describer **obj);

#endif
