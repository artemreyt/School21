/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:50:47 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 17:23:01 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <stdio.h>

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
	ft_strdel(&str);
	str = buf;
	return (str);
}

void	print_few_times(t_buffer *buffer, char c, size_t n)
{
	char	*str;

	str = (char *)ft_memalloc(n + 1);
	ft_memset(str, c, n);
	buf_putstr(buffer, str);
	ft_strdel(&str);
}

void	lst_content_simple_free(void *ptr, size_t size)
{
	if (size > 0)
		ft_memdel((void**)&ptr);
}
