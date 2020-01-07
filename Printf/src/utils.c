/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:50:47 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/07 02:27:41 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

int		flag_is_found(e_flags flag, const flags_describer *describer)
{
	return (ft_lstfind(describer->flags, &flag, sizeof(flag)) ? 1 : 0);
}
