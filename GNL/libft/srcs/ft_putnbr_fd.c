/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:57:14 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/15 21:47:02 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int digit;
	int is_neg;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10)
	{
		is_neg = 1;
		if (n < 0)
			is_neg = -1;
		ft_putnbr_fd(is_neg * (n / 10), fd);
	}
	digit = n % 10;
	if (digit < 0)
		digit *= -1;
	ft_putchar_fd('0' + digit, fd);
}
