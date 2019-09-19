/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:37:33 by creicher          #+#    #+#             */
/*   Updated: 2019/09/19 21:09:20 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char		buffer[BUFF_SIZE];
	ssize_t			read_result;
	static t_list	*head;

	while (1)
	{
		read_result = read(fd, buffer, BUFF_SIZE);

	}
	if (read_result > 0)
		return (1);
	else if (!read_result)
		return (0);
	return (-1);
}
