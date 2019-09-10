/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:39:22 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 20:41:01 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	unsigned char casted;

	casted = (unsigned char)c;
	return ((casted >= 'A' && casted <= 'Z') || (casted >= 'a' && casted <= 'z'));
}
