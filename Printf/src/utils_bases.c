/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:16:08 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/07 02:37:57 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "utils.h"
#include "libft.h"
#include <stdio.h>

static	void	ft_upper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}


static size_t	count_digits(t_signed number, int base)
{
	size_t	count;

	count = 0;
	while (number)
	{
		number /= base;
		count++;
	}
	return (count);
}

static	char	*str_itoa_base(t_unsigned number, int base)
{
	size_t			len;
	char			*str;
	t_signed		digit;

	len = count_digits(number, base);
	str = (char *)ft_memalloc(len + 1);
	while (number)
	{
		digit = number % base;
		str[--len] = (digit <= 9 ? digit + '0' : 'a' + digit - 10);
		number /= base;
	}
	return (str);
}

char			*get_str_base2(t_unsigned number, char specifier)
{
	char	*str;
	int		base;

	str = NULL;
	if (specifier == 'o')
		base = 8;
	else if (specifier == 'x' || specifier == 'X')
		base = 16;
	str = str_itoa_base(number, base);
	if (specifier == 'X')
		ft_upper(str);
	return (str);
}