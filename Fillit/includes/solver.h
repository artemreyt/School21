/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 01:34:50 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/14 17:19:36 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "libft.h"
# include "map.h"
# include "tetramino.h"

# define TETRAMINO_MIN_SQUARE 4

t_map	*solver(int fd);
int		solve(t_map *map, t_list *tetralist, char fill_char);

#endif
