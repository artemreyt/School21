/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 19:21:06 by creicher          #+#    #+#             */
/*   Updated: 2020/02/12 21:13:24 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"
#include "libft.h"
#include "ft_printf.h"
#include "t_buffer.h"

static int	extra_init(t_extra *extra)
{
	t_state_visual	default_visual;

	extra->visuals_stack = NULL;
	default_visual = create_state_base_of(DEFAULT_VISUALS_CODE, extra);
	extra->visuals_stack = ft_lstnew(&default_visual, sizeof(default_visual));
	return (extra->visuals_stack != NULL);
}

static int	printf_doing(const char *format, va_list args_list,
							t_buffer *buffer)
{
	t_extra		extra;
	char		*end;

	if (!extra_init(&extra))
		return (0);
	end = (char *)format;
	while (*end)
	{
		if (*end == '%')
		{
			end++;
			if (specifier_handler(&end, args_list, buffer, &extra) < 0)
			{
				buf_print_all(buffer);
				ft_lstdel(&extra.visuals_stack, lst_content_simple_free);
				return (0);
			}
		}
		else
			buf_putchar(buffer, *(end++));
	}
	buf_print_all(buffer);
	ft_lstdel(&extra.visuals_stack, lst_content_simple_free);
	return (1);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	t_buffer	buffer;
	va_list		args_list;
	int			ret_val;

	create_buffer(&buffer, fd);
	va_start(args_list, format);
	if (!printf_doing(format, args_list, &buffer))
	{
		va_end(args_list);
		return (-1);
	}
	ret_val = buffer.total;
	va_end(args_list);
	return (ret_val);
}

int			ft_printf(const char *format, ...)
{
	t_buffer	buffer;
	va_list		args_list;
	int			ret_val;

	create_buffer(&buffer, STDOUT_FILENO);
	va_start(args_list, format);
	if (!printf_doing(format, args_list, &buffer))
	{
		va_end(args_list);
		return (-1);
	}
	ret_val = buffer.total;
	va_end(args_list);
	return (ret_val);
}
