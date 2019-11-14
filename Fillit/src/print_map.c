/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 02:16:14 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/13 20:12:14 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	print_map(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
			ft_putchar(map->data[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
