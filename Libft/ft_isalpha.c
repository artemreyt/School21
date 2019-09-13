/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:39:22 by creicher          #+#    #+#             */
/*   Updated: 2019/09/13 11:51:25 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdlib.h>

int		ft_isalpha(int c)
{
	unsigned char casted;

	casted = (unsigned char)c;
	// return ((casted >= (unsigned char)'A' && casted <= (unsigned char)'Z') ||
	// 	    (casted >= (unsigned char)'a' && casted <= (unsigned char)'z'));
	if ((casted >= (unsigned char)'A' && casted <= (unsigned char)'Z') ||
 	    (casted >= (unsigned char)'a' && casted <= (unsigned char)'z'))
 	    return (1);
 	return (0);
}

// int main()
// {
// 	ft_putnbr(isalpha(-1));
// 	ft_putnbr(ft_isalpha(-1));
// }
