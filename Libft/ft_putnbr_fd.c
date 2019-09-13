/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:57:14 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/13 13:25:42 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
// 	int digit;
	
// 	if (n < 0)
// 		ft_putchar_fd('-', fd);
// 	if (n / 10)
// 		ft_putnbr_fd(n / 10, fd);
// 	digit = n % 10;
// 	if (digit < 0)
// 		digit *= -1;
// 	ft_putchar_fd('0' + digit, fd);
	char *str = ft_itoa(n);
	ft_putstr_fd(ft_itoa(n), fd);
	free(str);
}