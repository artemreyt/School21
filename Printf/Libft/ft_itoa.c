/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:39:14 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/15 21:45:33 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		digit;

	len = count_digits(n);
	if (n < 0)
		len++;
	str = ft_strnew(len);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n < 0)
			str[0] = '-';
		while (n)
		{
			digit = n % 10;
			str[len - 1] = '0' + (digit > 0 ? digit : -digit);
			n /= 10;
			len--;
		}
	}
	return (str);
}
