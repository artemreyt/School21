/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_describer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:39:39 by creicher          #+#    #+#             */
/*   Updated: 2020/01/16 03:11:59 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "flags_describer.h"

flags_describer	*create_flags_describer() {
	flags_describer *obj;

	obj = (flags_describer *) malloc(sizeof(flags_describer));
	obj->flags = NULL;
	obj->precision.found = 0;
	obj->width = 0;
	obj->specifier = '@';
	return (obj);
}

static void		del(void *ptr, size_t size)
{
	free(ptr);
	(void)size;
}

void			destroy_flags_describer(flags_describer **obj) {
	ft_lstdel(&(*obj)->flags, del);
}

flags_describer	*find_flags(char **str) {
	flags_describer	*describer;
	int				stop;
	int				flag_width;

	describer = create_flags_describer();
	stop = 0;
	while (**str && !stop) {
		stop = 1;
		if ((flag_width = check_not_conv_flags(*str, describer)))
		{
			stop = 0;
			*str += flag_width;
		}
	}
	if (**str && (flag_width = check_width_precision(*str, describer)))
		*str += flag_width;
	if (**str && (flag_width = check_num_conv_flags(*str, describer)))
		*str += flag_width;
	if (**str)
		describer->specifier = *(*str++);
	return (describer);
}

