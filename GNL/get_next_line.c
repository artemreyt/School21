/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:37:33 by creicher          #+#    #+#             */
/*   Updated: 2019/09/24 23:02:30 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*add_file_to_list(t_list **files, const int fd)
{
	t_list	*current;

	current = *files;
	while (current)
	{
		if (current->content_size == (size_t)fd)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("", 1);
	current->content_size = fd;
	ft_lstadd(files, current);
	return (current);
}

static char		*get_substr(t_list *fd_link)
{
	char	*end_line;
	char	*sub;
	char	*str;

	str = (char *)fd_link->content;
	end_line = ft_strchr(str, '\n');
	if (end_line)
	{
		sub = ft_strsub(str, 0, end_line - str);
		fd_link->content = ft_strdup(end_line + 1);
		free(str);
		return (sub);
	}
	return (NULL);
}
static void		delete_fd_link(t_list **files, t_list *fd_link)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *files;
	while (current)
	{
		if (current == fd_link)
		{
			if (!prev)
				*files = fd_link->next;
			else
				prev->next = fd_link->next;
			free(fd_link->content);
			free(fd_link);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

static int		if_eof(t_list **files, t_list *fd_link, char **line)
{
	int		result;
	if (((char *)(fd_link->content))[0] != '\0')
	{
		*line = ft_strdup((char *)fd_link->content);
		result = 1;
	}
	else 
		result = 0;
	delete_fd_link(files, fd_link);
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	ssize_t			read_result;
	static t_list	*files;
	char			*tmp;
	t_list			*fd_link;

	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (-1);
	fd_link = add_file_to_list(&files, fd);
	while (!(*line = get_substr(fd_link)) && (read_result = read(fd, buffer, BUFF_SIZE)) > 0)
	{
			buffer[read_result] = '\0';
			tmp = (char *)fd_link->content;
			fd_link->content = ft_strjoin(tmp, buffer);
			free(tmp);
	}
	if (*line)
		return (1);
	if (read_result == 0)
		return (if_eof(&files, fd_link, line));
	return (-1);
}
