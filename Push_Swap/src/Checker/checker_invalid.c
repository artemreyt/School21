/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_invalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:14:53 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 12:38:14 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "ft_algorithms.h"
#include <stdlib.h>

static int	check_duplicates(int *arr, int n)
{
	int i;
	int *arr_copy;
	int ret_val;

	arr_copy = (int *)malloc(sizeof(*arr) * n);
	if (!arr_copy)
		return (0);
	ft_memcpy(arr_copy, arr, sizeof(*arr) * n);
	radix_sort(arr_copy, n);
	i = 0;
	ret_val = 1;
	while (i < n - 1)
	{
		if (arr_copy[i] == arr_copy[i + 1])
		{
			ret_val = 0;
			break ;
		}
		++i;
	}
	free(arr_copy);
	return (ret_val);
}

/*
	** both functions below
	** return number of digit arguments, return -1 if found non digit argument
*/

static int	count_one_argument(char *arg)
{
	int arg_i;
	int count;

	arg_i = 0;
	count = 0;
	while (arg[arg_i])
	{
		while (ft_strchr(WHITESPACES, arg[arg_i]))
			++arg_i;
		if (arg[arg_i] == '+' || arg[arg_i] == '-')
			++arg_i;
		if (ft_isdigit(arg[arg_i]))
		{
			++count;
			while (ft_isdigit(arg[arg_i]))
				++arg_i;
		}
		else if (arg[arg_i] && !ft_strchr(WHITESPACES, arg[arg_i]))
			return (-1);
	}
	return (count);
}

static int	count_arguments(int argc, char **argv)
{
	int i;
	int count;
	int res;

	i = 1;
	count = 0;
	while (i < argc)
	{
		res = count_one_argument(argv[i]);
		if (res == -1)
			return (res);
		count += res;
		++i;
	}
	return (count);
}

/*
	** returns 1, if arguments successfully parsed
	** returns 0, if there are duplicates or int overflow
*/

static int	parse_arguments(int argc, char **argv, int *arr)
{
	int			i;
	int			i_arr;
	const char	*str;

	i = 1;
	i_arr = 0;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			while (ft_strchr(WHITESPACES, *str))
				++str;
			if (*str)
			{
				if (!ft_atoi_safe(str, &str, &arr[i_arr++]))
					return (0);
			}
		}
		++i;
	}
	return (1);
}

int			checker_parse_arguments(int argc, char **argv, int **arr, int *size)
{
	*size = count_arguments(argc, argv);
	if (*size == -1)
		return (0);
	*arr = (int *)malloc(sizeof(int) * (*size));
	if (!(*arr))
		return (0);
	if (!parse_arguments(argc, argv, *arr))
	{
		free(*arr);
		return (0);
	}
	if (!check_duplicates(*arr, *size))
	{
		free(*arr);
		return (0);
	}
	return (1);
}
