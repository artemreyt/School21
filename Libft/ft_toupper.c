/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:55:19 by creicher          #+#    #+#             */
/*   Updated: 2019/09/13 13:11:52 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_toupper(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return ('A' + (c - 'a'));
	return (c);
}

// int main()
// {
// 	ft_putchar(ft_toupper('m'));
// }