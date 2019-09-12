/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:39:22 by creicher          #+#    #+#             */
/*   Updated: 2019/09/12 23:42:14 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int		ft_isalpha(int c)
{
	unsigned char casted;

	casted = (unsigned char)c;
	return ((casted >= 'A' && casted <= 'Z') || (casted >= 'a' && casted <= 'z'));
}
