/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:16:08 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 16:52:04 by creicher         ###   ########.fr       */
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

static size_t	count_digits(t_unsigned number, int base)
{
	size_t	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number)
	{
		number /= base;
		count++;
	}
	return (count);
}

char			*ft_itoa_base(t_unsigned number, int base)
{
	size_t			len;
	char			*str;
	t_signed		digit;

	if (number == 0)
		return (ft_strdup("0"));
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
	else if (specifier == 'b')
		base = 2;
	else
		base = 16;
	str = ft_itoa_base(number, base);
	if (specifier == 'X')
		ft_upper(str);
	return (str);
}
