/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:50:47 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/17 16:32:50 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

int		flag_is_found(e_flags flag, const flags_describer *describer)
{
	return (ft_lstfind(describer->flags, &flag, sizeof(flag)) ? 1 : 0);
}

char	*append_few_letters(char *str, char c, size_t n)
{
	size_t	i;
	char	*buf;
	size_t	str_len;

	str_len = ft_strlen(str);
	buf = ft_memalloc(str_len + n + 1);
	ft_strcpy(buf, str);
	i = str_len;
	while (n--)
		buf[i++] = c;

	// puts("BEFORE");
	
	free(str);

	// puts("AFTER");
	
	str = buf;
	return (str);
}

void	print_few_times(char c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(n);
	i = 0;
	while (i < n)
		str[i++] = c;
	write(1, str, n);
	free(str);
}
