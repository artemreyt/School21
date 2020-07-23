/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:47:00 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 12:47:25 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int *arr;
	int size;

	if (!checker_parse_arguments(argc, argv, &arr, &size))
	{
		ft_putendl(ERROR_MSG);
		return (1);
	}
	launch_push_swap(arr, size);
	free(arr);
	return (0);
}
