/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:42:51 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/24 00:31:14 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_llulen(unsigned long long n)
{
	size_t	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static	void	ft_llutoa(unsigned long long num, char *s)
{
	if (num > 9)
	{
		ft_llutoa(num / 10, s - 1);
	}
	*s = num % 10 + '0';
}

char			*ft_itoa(int n)
{
	int					negative;
	size_t				numlen;
	unsigned long long	num;
	char				*str;

	negative = 0;
	numlen = 0;
	if (n < 0)
		negative = 1;
	num = (unsigned long long)(ft_abs((long long)n));
	numlen = ft_llulen(num);
	str = (char*)malloc((numlen + negative + 1) * sizeof(*str));
	if (str != NULL)
	{
		if (negative == 1)
			*str = '-';
		ft_llutoa(num, str + numlen + negative - 1);
		str[numlen + negative] = '\0';
	}
	return (str);
}
