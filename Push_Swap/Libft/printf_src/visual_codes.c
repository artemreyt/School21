/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_codes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:23:19 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 17:23:31 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuals.h"

int		is_text_type_visual(int code)
{
	return (0 < code && code < 8 && code != 3 && code != 6);
}

int		is_fgnd_visual(int code)
{
	return ((30 <= code && code <= 37) ||
			(90 <= code && code <= 97));
}

int		is_bgnd_visual(int code)
{
	return ((40 <= code && code <= 47) ||
			(100 <= code && code <= 107));
}
