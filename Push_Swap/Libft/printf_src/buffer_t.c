/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_t.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:20:08 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 15:34:39 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_buffer.h"
#include <unistd.h>

void		create_buffer(t_buffer *buffer, int fd)
{
	buffer->fd = fd;
	buffer->real_size = 0;
	buffer->total = 0;
}

void		buf_putchar(t_buffer *buffer, char c)
{
	if (buffer->real_size + 1 == BUF_SIZE)
		buf_print_all(buffer);
	buffer->buf[buffer->real_size] = c;
	buffer->real_size++;
}

void		buf_putstr(t_buffer *buffer, const char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (buffer->real_size + len >= BUF_SIZE)
	{
		buf_print_all(buffer);
		if (len >= BUF_SIZE)
		{
			write(buffer->fd, str, len);
			return ;
		}
	}
	ft_memcpy(buffer->buf + buffer->real_size, str, len);
	buffer->real_size += len;
}

void		buf_print_all(t_buffer *buffer)
{
	write(buffer->fd, buffer->buf, buffer->real_size);
	buffer->total += buffer->real_size;
	buffer->real_size = 0;
}
