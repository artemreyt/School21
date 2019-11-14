/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:47:31 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/14 17:21:26 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H
# define TETRAMINO_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define NUMBER_POINTS 4
# define TETRAMINO_ROWS 4
# define TETRAMINO_COLS 4
# define BLOCK_CHAR '#'
# define EMPTY_CHAR '.'
# define TETRAMINO_BLOCK_SIZE (ssize_t)20

# define MAX(x, y) (x >= y ? x : y)
# define MIN(x, y) (x <= y ? x : y)

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetramino
{
	t_point	points[NUMBER_POINTS];
	size_t	height;
	size_t	offset_left;
	size_t	offset_right;
}				t_tetramino;

t_list			*read_tetraminos(int fd);
t_tetramino		*new_tetramino(char *char_tetramino);
void			delete_tetralist(t_list **tetralist);

#endif
