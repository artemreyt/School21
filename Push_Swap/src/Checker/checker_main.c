/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:38:53 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 12:40:20 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int ret_code;

	if (argc == 1)
		return (0);
	ret_code = launch_checker(argc, argv);
	if (ret_code == OK_CODE)
		ft_putendl(OK_MSG);
	else if (ret_code == KO_CODE)
		ft_putendl(KO_MSG);
	else if (ret_code == ERROR_CODE)
		ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	else
		ft_putendl_fd("UNKNOWN RETURN CODE", STDERR_FILENO);
	return (ret_code);
}
