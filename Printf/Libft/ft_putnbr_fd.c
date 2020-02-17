/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 07:10:47 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/24 00:30:27 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recprintd_unsafe_fd(unsigned long long num, int fd)
{
	if (num > 9)
	{
		ft_recprintd_unsafe_fd(num / 10, fd);
	}
	ft_putchar_fd(num % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long long	num;

	if (fd != -1)
	{
		num = (long long)n;
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num = -num;
		}
		ft_recprintd_unsafe_fd((unsigned long long)num, fd);
	}
}
