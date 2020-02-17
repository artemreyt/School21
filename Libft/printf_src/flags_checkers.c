/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 00:15:42 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 19:52:21 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"

static t_flags	get_flag(const char *str)
{
	if (ft_strncmp("hh", str, 2) == 0)
		return (hh_FLAG);
	else if (*str == 'h')
		return (h_FLAG);
	else if (ft_strncmp("ll", str, 2) == 0)
		return (ll_FLAG);
	else if (*str == 'l')
		return (l_FLAG);
	else if (*str == 'L')
		return (L_FLAG);
	else if (*str == 'z')
		return (z_FLAG);
	else if (*str == 'j')
		return (j_FLAG);
	return (NILL_FLAG);
}

/*
	** returns width of is_found flags,
	** 0 if not
*/

int				check_num_conv_flags(const char *str, t_fdescriber *describer)
{
	int		count;
	t_flags	flag;

	count = 0;
	while (str[count])
	{
		flag = get_flag(str + count);
		if (flag == NILL_FLAG)
			break ;
		add_flag(flag, describer);
		count += (flag == hh_FLAG || flag == ll_FLAG ? 2 : 1);
	}
	return (count);
}

int				check_not_conv_flags(const char *str, t_fdescriber *describer)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (ft_strncmp("#", str + count, 1) == 0)
			add_flag(HASH_FLAG, describer);
		else if (ft_strncmp("+", str + count, 1) == 0)
			add_flag(PLUS_FLAG, describer);
		else if (ft_strncmp("-", str + count, 1) == 0)
			add_flag(MINUS_FLAG, describer);
		else if (ft_strncmp("0", str + count, 1) == 0)
			add_flag(ZERO_FLAG, describer);
		else if (ft_strncmp(" ", str + count, 1) == 0)
			add_flag(SPACE_FLAG, describer);
		else
			break ;
		count++;
	}
	return (count);
}
