/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 07:27:19 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/23 18:39:19 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapc(char *cfirst, char *csecond)
{
	char	tmp;

	if (cfirst != NULL && csecond != NULL)
	{
		tmp = *cfirst;
		*cfirst = *csecond;
		*csecond = tmp;
	}
}
