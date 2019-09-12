/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:37:31 by creicher          #+#    #+#             */
/*   Updated: 2019/09/11 23:51:57 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int digit;
	
	if (n < 0)
		ft_putchar('-');
	if (n / 10)
		ft_putnbr(n / 10);
	digit = n % 10;
	if (digit < 0)
		digit *= -1;
	ft_putchar('0' + digit);
}
