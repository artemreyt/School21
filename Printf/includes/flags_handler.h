/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:15:49 by creicher          #+#    #+#             */
/*   Updated: 2019/12/30 22:56:31 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_HANDLER_H
# define FLAGS_HANDLER_H

#include <stdarg.h>

# define HH_FLAG	1
# define H_FLAG		2
# define L_FLAG		3
# define LL_FLAG	4
# define HASH_FLAG	5
# define ZERO_FLAG	6
# define PLUS_FLAG	7
# define STAR_FLAG	8

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

flags_describer *find_flags(const char *str);
flags_describer *create_flags_describer();
void			destroy_flags_describer(flags_describer **obj);

#endif
