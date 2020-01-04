/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 00:15:42 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/04 03:23:13 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_handler.h"
#include "libft.h"

/*
	** returns width of found flags,
	** 0 if not
*/
static int		check_num_conv_flags(const char *str, flags_describer *describer) {
	e_flags	flag;

	if (ft_strncmp("hh", str, 2) == 0)
		flag = hh_FLAG; 
	else if (ft_strncmp("h", str, 1) == 0)
		flag = h_FLAG;
	else if (ft_strncmp("ll", str, 2) == 0)
		flag = ll_FLAG;
	else if (ft_strncmp("l", str, 1) == 0)
		flag = l_FLAG;
	else if (ft_strncmp("L", str, 1) == 0)
		flag = L_FLAG;
	else
		return (0);
	ft_lstadd(&describer->flags, ft_lstnew(&flag, sizeof(flag)));
	return (flag == hh_FLAG || flag == ll_FLAG ? 2 : 1);
}

static int		check_width_precision(const char *str, flags_describer *describer) {
	int	width;
	int i;
	int precision;

	i = 0;
	if ((width = ft_atoi(str))) {
		while (ft_isdigit(str[i]))
			i++;
	}
	describer->width = width;
	if (str[i] == '.') {
		i++;
		precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
		describer->precision.found = 1;
		describer->precision.value = precision;
	}
	return (i);
}

static int		check_not_conv_flags(const char *str, flags_describer *describer) {
	e_flags	flag;

	if (ft_strncmp("#", str, 1) == 0)
		flag = HASH_FLAG;
	else if (ft_strncmp("+", str, 1) == 0)
		flag = PLUS_FLAG;
	else if (ft_strncmp("-", str, 1) == 0)
		flag = MINUS_FLAG;
	else if (ft_strncmp("0", str, 1) == 0)
		flag = ZERO_FLAG;
	else
		return (0);
	ft_lstadd(&describer->flags, ft_lstnew(&flag, sizeof(flag)));
	return (1);
}

flags_describer	*find_flags(char **str) {
	flags_describer	*describer;
	int				stop;
	int				flag_width;

	describer = create_flags_describer();
	stop = 0;
	while (!stop) {
		stop = 1;
		if ((flag_width = check_not_conv_flags(*str, describer)))
		{
			stop = 0;
			*str += flag_width;
		}
	}
	if ((flag_width = check_width_precision(*str, describer)))
		*str += flag_width;
	if ((flag_width = check_num_conv_flags(*str, describer)))
		*str += flag_width;
	return (describer);
}
