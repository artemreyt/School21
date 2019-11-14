/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:48:25 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/14 17:18:19 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "tetramino.h"

typedef struct	s_map
{
	size_t	size;
	char	**data;
}				t_map;

t_map			*new_map(size_t size);
void			del_map(t_map **map);
t_point			insert_tetramino(t_map *map,
						t_tetramino *tetramino, t_point *start, char fill_char);
void			erase_tetramino(t_map *map,
						t_tetramino *tetramino, t_point *start);
void			print_map(t_map *map);

#endif
