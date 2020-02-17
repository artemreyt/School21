/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 07:25:20 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/20 06:24:58 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapi(int *ifirst, int *isecond)
{
	int		tmp;

	if (ifirst != NULL && isecond != NULL)
	{
		tmp = *ifirst;
		*ifirst = *isecond;
		*isecond = tmp;
	}
}
