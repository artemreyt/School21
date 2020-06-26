/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_describer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:10:38 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 16:34:34 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "flags_describer.h"

void			init_t_fdescriber(t_fdescriber *obj)
{
	obj->flags = 0;
	obj->precision.is_found = 0;
	obj->width = 0;
	obj->specifier = '@';
}

t_fdescriber	*find_flags(t_fdescriber *describer, char **str,
							va_list args_list)
{
	int				stop;
	int				flag_width;

	stop = 0;
	while (**str && !stop)
	{
		stop = 1;
		if ((flag_width = check_not_conv_flags(*str, describer)))
			*str += flag_width;
		stop = (flag_width ? 0 : stop);
		if (**str &&
			(flag_width = check_width_precision(*str, describer, args_list)))
		{
			*str += flag_width;
			stop = 0;
		}
		if (**str && (flag_width = check_num_conv_flags(*str, describer)))
		{
			*str += flag_width;
			stop = 0;
		}
	}
	describer->specifier = **str ? *((*str)++) : '@';
	return (describer);
}

inline void		add_flag(t_flags flag, t_fdescriber *describer)
{
	describer->flags |= 0x01 << flag;
}

inline int		flag_is_found(t_flags flag, const t_fdescriber *describer)
{
	return ((describer->flags >> flag) & 0x01);
}
