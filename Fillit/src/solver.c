/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:47:36 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/14 21:55:23 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static size_t	get_min_size(size_t tetramino_count)
{
	size_t	size;
	size_t	min_square;

	min_square = TETRAMINO_MIN_SQUARE * tetramino_count;
	size = 0;
	while (size * size < min_square)
		size++;
	return (size);
}

t_map			*solver(int fd)
{
	t_list	*tetralist;
	size_t	map_size;
	size_t	tetraminos_count;
	t_map	*map;

	tetralist = read_tetraminos(fd);
	tetraminos_count = ft_lstsize(tetralist);
	map_size = get_min_size(tetraminos_count);
	map = NULL;
	while (!map)
	{
		map = new_map(map_size);
		if (!solve(map, tetralist, 'A'))
		{
			del_map(&map);
			map_size++;
		}
	}
	delete_tetralist(&tetralist);
	return (map);
}

int				solve(t_map *map, t_list *tetralist, char fill_char)
{
	t_point	start_point;

	if (!tetralist)
		return (1);
	start_point = (t_point){0, 0};
	while (1)
	{
		start_point = insert_tetramino(map,
				tetralist->content, &start_point, fill_char);
		if (start_point.x == -1)
			break ;
		if (solve(map, tetralist->next, fill_char + 1))
			return (1);
		erase_tetramino(map, tetralist->content, &start_point);
		start_point.x++;
	}
	return (0);
}
