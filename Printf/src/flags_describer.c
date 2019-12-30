/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_describer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:39:39 by creicher          #+#    #+#             */
/*   Updated: 2019/12/30 23:03:47 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "flags_handler.h"

flags_describer	*create_flags_describer() {
	flags_describer *obj;

	obj = (flags_describer *) malloc(sizeof(flags_describer));
	obj->flags = NULL;
	obj->precision.found = 0;
	obj->width = 0;
	return (obj);
}

static void	del(void *ptr, size_t size)
{
	free(ptr);
	(void)size;
}

void			destroy_flags_describer(flags_describer **obj) {
	ft_lstdel(&(*obj)->flags, del);
}

