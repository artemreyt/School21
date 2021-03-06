/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_itoas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:38:54 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 17:22:36 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

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
			str[(plus ? 1 : 0)] = '0';
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

static t_signed	u_count_digits(t_unsigned n)
{
	t_unsigned count;

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

char			*ft_unsigned_itoa(t_unsigned n)
{
	size_t		len;
	char		*str;
	t_unsigned	digit;

	if (n == 0)
		return (ft_strdup("0"));
	len = u_count_digits(n);
	str = ft_strnew(len);
	if (str)
	{
		while (n)
		{
			digit = n % 10;
			str[len - 1] = (char)('0' + digit);
			n /= 10;
			len--;
		}
	}
	return (str);
}
