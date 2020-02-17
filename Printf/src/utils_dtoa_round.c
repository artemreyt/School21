/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dtoa_round.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:18:00 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 17:17:11 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		add_digit(char *dest)
{
	if (*dest == '9')
	{
		*dest = '0';
		return (1);
	}
	else if (*dest == '.')
		return (1);
	(*dest)++;
	return (0);
}

static char		*add_to_int_part(t_float number, int add)
{
	if (add)
		number++;
	return (get_int_part(number));
}

char			*ft_str_round(t_float number, int precision, int minus)
{
	int		i;
	int		continue_add;
	char	*int_part;
	char	*fract_part;
	char	*str;

	fract_part = get_fract_part(number, precision + 1);
	i = precision + 1;
	continue_add = 0;
	if (fract_part[i] >= '5')
		continue_add = add_digit(&fract_part[i - 1]);
	i -= fract_part[i - 1] != '.' ? 1 : 0;
	while (fract_part[i-- - 1] != '.')
		if (continue_add)
			continue_add = add_digit(&fract_part[i]);
	fract_part[precision > 0 ? precision + 1 : 0] = '\0';
	int_part = add_to_int_part(number, continue_add);
	i = ft_strlen(int_part) + ft_strlen(fract_part);
	str = (char *)ft_memalloc(i + 2);
	str[0] = (minus ? '-' : str[0]);
	ft_strcat(str, int_part);
	ft_strcat(str, fract_part);
	ft_strdel(&int_part);
	ft_strdel(&fract_part);
	return (str);
}
