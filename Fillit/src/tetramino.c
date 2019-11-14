/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:39:00 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/13 23:40:30 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

static void		move_up_left(char *char_tetramino, int up, int left)
{
	int i;
	int j;
	int new_i;
	int new_j;

	if (!up && !left)
		return ;
	i = 0;
	while (i < TETRAMINO_ROWS)
	{
		j = 0;
		while (j < TETRAMINO_COLS)
		{
			if (char_tetramino[i * TETRAMINO_ROWS + j + i] == BLOCK_CHAR)
			{
				new_i = i - up;
				new_j = j - left;
				char_tetramino[new_i * TETRAMINO_ROWS + new_j + new_i] =
															BLOCK_CHAR;
				char_tetramino[i * TETRAMINO_ROWS + j + i] = EMPTY_CHAR;
			}
			j++;
		}
		i++;
	}
}

static void		align(char *char_tetramino)
{
	int i;
	int j;
	int left;
	int up;

	left = -1;
	up = -1;
	i = 0;
	while (i < TETRAMINO_ROWS)
	{
		j = 0;
		while (j < TETRAMINO_COLS)
		{
			if (char_tetramino[i * TETRAMINO_ROWS + j + i] == BLOCK_CHAR)
			{
				if (left == -1 || j < left)
					left = j;
				if (up == -1)
					up = i;
			}
			j++;
		}
		i++;
	}
	move_up_left(char_tetramino, up, left);
}

static void		set_offsets(t_tetramino *tetramino)
{
	size_t	i;
	int		left;
	int		right;

	left = tetramino->points[0].x;
	right = tetramino->points[0].x;
	i = 1;
	while (i < NUMBER_POINTS)
	{
		left = MIN(left, tetramino->points[i].x);
		right = MAX(right, tetramino->points[i].x);
		i++;
	}
	tetramino->offset_left = tetramino->points[0].x - left;
	tetramino->offset_right = right - tetramino->points[0].x;
}

static void		set_meta(char *char_tetramino, t_tetramino *tetramino)
{
	size_t	i;
	size_t	j;
	int		point_id;

	point_id = 0;
	tetramino->height = 0;
	i = 0;
	while (i < TETRAMINO_ROWS)
	{
		j = 0;
		while (j < TETRAMINO_COLS)
		{
			if (char_tetramino[i * TETRAMINO_ROWS + j + i] == BLOCK_CHAR)
			{
				tetramino->height = i + 1;
				tetramino->points[point_id++] = (t_point){j, i};
			}
			j++;
		}
		i++;
	}
	set_offsets(tetramino);
}

t_tetramino		*new_tetramino(char *char_tetramino)
{
	t_tetramino *tetramino;

	tetramino = (t_tetramino *)malloc(sizeof(t_tetramino));
	if (!tetramino)
		return (NULL);
	align(char_tetramino);
	set_meta(char_tetramino, tetramino);
	return (tetramino);
}
