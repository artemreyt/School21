/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:37:31 by creicher          #+#    #+#             */
/*   Updated: 2019/09/13 17:36:03 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int digit;

	if (n < 0)
		ft_putchar('-');
	if (n / 10)
	{
		int is_neg;

		is_neg = 1;
		if (n < 0)
			is_neg = -1;
		ft_putnbr(is_neg * (n / 10));
	}
	digit = n % 10;
	if (digit < 0)
		digit *= -1;
	ft_putchar('0' + digit);
	// char *str = ft_itoa(n);
	// ft_putstr(str);
	// free(str);
}
