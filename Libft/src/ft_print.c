/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:27:48 by creicher          #+#    #+#             */
/*   Updated: 2019/09/09 20:36:43 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include "ft_print.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(const char *str)
{
	while (*str)
		ft_putchar(*str++);
}
void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int main()
{
	ft_putchar('H');
	ft_putstr("\nHello, world!\n");
	ft_putnbr(-29398);
}