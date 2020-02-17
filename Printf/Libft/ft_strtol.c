/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:48:20 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/15 18:14:27 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	calc_base(const char **str, int *bptr, int *isnegptr)
{
	const char	*s;
	int			base;

	s = *str;
	base = *bptr;
	*isnegptr = 0;
	while (ft_isspace(*s))
		++s;
	if ((*s == '-' || *s == '+') && *(s++) == '-')
		*isnegptr = 1;
	if ((base == 0 || base == 16)
			&& *s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
	{
		s += 2;
		base = 16;
	}
	else if (base == 0 && *s == '0')
	{
		base = 8;
		++s;
	}
	else if (base == 0 && *s != '0')
		base = 10;
	*bptr = base;
	*str = s;
}

static int	accumulate(const char **str, int base, unsigned long cuts[2],
		unsigned long *acc)
{
	int			status;
	int			c;

	status = 0;
	while ((c = (int)**str) != '\0')
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
			c -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break ;
		if (c >= base)
			break ;
		if (status < 0 || *acc > cuts[0] || (*acc == cuts[0] &&
					(unsigned long)c > cuts[1]))
			status = -1;
		else
		{
			status = 1;
			*acc = *acc * base + c;
		}
		++(*str);
	}
	return (status);
}

static int	mult_with_ovr_checks(const char **str, int base,
		int isneg, unsigned long *acc)
{
	unsigned long	cutoff;
	unsigned long	cutlim;
	unsigned long	cuts[2];

	if (base < 0 || base == 1 || base > 36)
		return (0);
	cutoff = isneg ? -((unsigned long)LONG_MIN) : LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;
	cuts[0] = cutoff;
	cuts[1] = cutlim;
	return (accumulate(str, base, cuts, acc));
}

long		ft_strtol(const char *str, char **endptr, int base)
{
	const char		*s;
	unsigned long	acc;
	int				isneg;
	int				status;

	acc = 0;
	if (str != NULL)
	{
		s = str;
		calc_base(&s, &base, &isneg);
		status = mult_with_ovr_checks(&s, base, isneg, &acc);
		if (status < 0)
			acc = isneg ? LONG_MIN : LONG_MAX;
		else if (isneg)
			acc = -acc;
		if (endptr != NULL)
			*endptr = status != 0 ? (char*)s : (char*)str;
	}
	return ((long)acc);
}
