/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buffer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:06:47 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/12 21:05:49 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BUFFER_H
# define T_BUFFER_H

# define BUF_SIZE 128

struct		s_buffer
{
	char	buf[BUF_SIZE];
	int		real_size;
	int		total;
	int		fd;
};
typedef struct s_buffer	t_buffer;

void		create_buffer(t_buffer *buffer, int fd);
void		buf_putchar(t_buffer *buffer, char c);
void		buf_putstr(t_buffer *buffer, const char *str);
void		buf_print_all(t_buffer *buffer);

#endif
