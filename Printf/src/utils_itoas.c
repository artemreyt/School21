/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:38:54 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/07 00:54:33 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

static t_signed	count_digits(t_signed n)
{
	t_signed count;

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

char			*ft_signed_itoa(t_signed n, int plus)
{
	size_t		len;
	char		*str;
	t_signed	digit;

	len = count_digits(n);
	if (n < 0 || plus)
		len++;
	str = ft_strnew(len);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n < 0)
			str[0] = '-';
		else if (plus)
			str[0] = '+';
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

char			*ft_unsigned_itoa(t_unsigned n)
{
	size_t		len;
	char		*str;
	t_unsigned	digit;

	len = count_digits(n);
	str = ft_strnew(len);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		while (n)
		{
			digit = n % 10;
			str[len - 1] = '0' + digit;
			n /= 10;
			len--;
		}
	}
	return (str);
}

