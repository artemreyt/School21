/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:23:35 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/11/14 17:23:35 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solver.h"
#include <fcntl.h>
#include "validation.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" fillit_file");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_with_error(NULL);
	map = solver(fd);
	if (!map)
	{
		ft_putendl("error");
		close(fd);
		return (1);
	}
	print_map(map);
	del_map(&map);
	close(fd);
	return (0);
}
