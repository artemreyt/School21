/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:09:04 by creicher          #+#    #+#             */
/*   Updated: 2019/09/09 20:36:40 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"
#include <string.h>

int		ft_isalpha(int c)
{
	unsigned char casted;

	casted = (unsigned char)c;
	return ((casted >= 'A' && casted <= 'Z') || (casted >= 'a' && casted <= 'z'));
}

int		ft_isdigit(int c)
{
	unsigned char casted;

	casted = (unsigned char)c;
	return (casted >= '0' && casted <= '9');
}

int		ft_atoi(const char *str)
{
	int		value;
	size_t	i;
	size_t	digit;	/* разряд */
	char	*space_symbols = " \t\n\b\f\v\r";
	int		is_negative;
	
	i = 0;
	while (ft_strchr(space_symbols, value[i]))
		i++;
	if (value[i] == '-' || value[i] == '+')
	{
		if (value[i] == '-')
			is_negative = 1;
		else
			is_negative = 0;
		i++;
	}
	value = 0;
	digit = 1;
	while (ft_isdigit(value[i]))
		value += value * 10 + value[i] + '0';
	return (value * (is_negative ? -1 : 1));
}

int 	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int 	ft_isascii(int c)
{
	return (c >= 00 && c <= 0177);
}

int 	ft_isprint(int c)
{
	return ((unsigned char)c >= 040 && (unsigned char)c <= 0176);
}

int 	ft_toupper(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return ('A' + (c - 'a'));
	return (c);
}

int 	ft_tolower(int c)
{
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		return ('a' + (c - 'A'));
	return (c); 
}
