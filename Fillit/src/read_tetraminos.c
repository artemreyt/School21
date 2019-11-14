/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetraminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:47:25 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/14 17:22:50 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"
#include "validation.h"

static void	del(void *ptr, size_t size)
{
	free(ptr);
	(void)size;
}

void		delete_tetralist(t_list **tetralist)
{
	ft_lstdel(tetralist, del);
}

static int	read_block(int fd, t_list **tetralist)
{
	ssize_t		read_bytes;
	char		buffer[TETRAMINO_BLOCK_SIZE + 1];
	t_tetramino *tetramino;

	read_bytes = read(fd, buffer, TETRAMINO_BLOCK_SIZE);
	if (read_bytes < TETRAMINO_BLOCK_SIZE || !check_valid_block(buffer))
		exit_with_error(tetralist);
	buffer[read_bytes] = '\0';
	if ((tetramino = new_tetramino(buffer)) != NULL)
	{
		ft_lst_pushback(tetralist, tetramino, sizeof(t_tetramino));
		free(tetramino);
		tetramino = NULL;
	}
	else
		exit_with_error(tetralist);
	if ((read_bytes = read(fd, buffer, 1)) == 0)
		return (0);
	else if (read_bytes != 1 || buffer[0] != '\n')
		exit_with_error(tetralist);
	return (1);
}

t_list		*read_tetraminos(int fd)
{
	t_list		*tetralist;
	int			res_read_block;
	int			count;

	tetralist = NULL;
	count = 0;
	while (count++ < MAX_TETRAMINOS_NUMBER)
	{
		res_read_block = read_block(fd, &tetralist);
		if (res_read_block == 0)
			break ;
	}
	if (count > MAX_TETRAMINOS_NUMBER)
		exit_with_error(&tetralist);
	return (tetralist);
}
