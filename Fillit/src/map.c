/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:58:16 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/13 19:39:40 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map		*new_map(size_t size)
{
	t_map	*new_map;
	size_t	i;
	size_t	j;

	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->size = size;
	new_map->data = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		new_map->data[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
			new_map->data[i][j++] = EMPTY_CHAR;
		i++;
	}
	return (new_map);
}

void		del_map(t_map **map)
{
	size_t i;

	i = 0;
	while (i < (*map)->size)
		free((*map)->data[i++]);
	free((*map)->data);
	free(*map);
	*map = NULL;
}

static int	try_insert(t_map *map, t_tetramino *tetramino,
							t_point *start, char fill_char)
{
	size_t	i;
	t_point	point;
	int		checked;

	i = 0;
	checked = 0;
	while (i < NUMBER_POINTS)
	{
		point.x = start->x + (tetramino->points[i].x - tetramino->offset_left);
		point.y = start->y + tetramino->points[i].y;
		if (!checked)
		{
			if (map->data[point.y][point.x] != EMPTY_CHAR)
				return (0);
			if (++i == NUMBER_POINTS)
			{
				i = 0;
				checked = 1;
			}
			continue;
		}
		map->data[point.y][point.x] = fill_char;
		i++;
	}
	return (1);
}

/*
	** returns {-1, -1}, if not available
	** returns {x, y}, if tetramino was inserted on x, y coords
*/

t_point		insert_tetramino(t_map *map,
					t_tetramino *tetramino, t_point *start, char fill_char)
{
	int x;
	int y;

	x = start->x;
	y = start->y;
	while (y + tetramino->height <= map->size)
	{
		while (x + tetramino->offset_right < map->size)
		{
			if (tetramino->offset_left <= (size_t)x
				&& map->data[y][x] == EMPTY_CHAR)
			{
				if (try_insert(map, tetramino, &(t_point){x, y}, fill_char))
					return ((t_point){x, y});
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ((t_point){-1, -1});
}

void		erase_tetramino(t_map *map, t_tetramino *tetramino, t_point *start)
{
	int		x;
	int		y;
	size_t	i;

	i = 0;
	while (i < NUMBER_POINTS)
	{
		x = start->x + (tetramino->points[i].x - tetramino->offset_left);
		y = start->y + tetramino->points[i].y;
		map->data[y][x] = EMPTY_CHAR;
		i++;
	}
}
