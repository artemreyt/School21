/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:04:19 by creicher          #+#    #+#             */
/*   Updated: 2019/11/14 17:22:42 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "tetramino.h"
#include <stdio.h>

void		exit_with_error(t_list **tetralist)
{
	if (tetralist)
		delete_tetralist(tetralist);
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

/*
	** checks valid of char string
	** size of TETRAMINO_BLOCK_SIZE which represents tetramino
*/

static int	count_touch(char *char_tetramino, int i, int j)
{
	int	touches;

	touches = 0;
	if (i != 0)
		touches += (char_tetramino[(i - 1) * TETRAMINO_COLS + j + (i - 1)]
					== BLOCK_CHAR);
	if (i != TETRAMINO_ROWS - 1)
		touches += (char_tetramino[(i + 1) * TETRAMINO_COLS + j + (i + 1)]
					== BLOCK_CHAR);
	if (j != 0)
		touches += (char_tetramino[i * TETRAMINO_COLS + j - 1 + i]
					== BLOCK_CHAR);
	if (j != TETRAMINO_COLS - 1)
		touches += (char_tetramino[i * TETRAMINO_COLS + j + 1 + i]
					== BLOCK_CHAR);
	return (touches);
}

int			check_row(char *char_tetramino,
					int i, int *touches, int *count_blocks)
{
	int j;

	j = 0;
	while (j < TETRAMINO_COLS)
	{
		if (char_tetramino[i * TETRAMINO_COLS + j + i] == BLOCK_CHAR)
		{
			(*count_blocks)++;
			*touches += count_touch(char_tetramino, i, j);
		}
		else if (char_tetramino[i * TETRAMINO_COLS + j + i] != EMPTY_CHAR)
			return (0);
		j++;
	}
	if (char_tetramino[i * TETRAMINO_COLS + TETRAMINO_COLS + i] != '\n')
		return (0);
	return (1);
}

int			check_valid_block(char *char_tetramino)
{
	int	i;
	int	count_blocks;
	int	touches;

	i = 0;
	count_blocks = 0;
	touches = 0;
	while (i < TETRAMINO_ROWS)
	{
		if (!check_row(char_tetramino, i, &touches, &count_blocks))
			return (0);
		i++;
	}
	if (count_blocks != NUMBER_POINTS || touches < MIN_TOUCHES)
		return (0);
	return (1);
}
