/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:25:01 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/20 06:23:48 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapp(void **pfirst, void **psecond)
{
	void	*tmp;

	if (pfirst != NULL && psecond != NULL)
	{
		tmp = *pfirst;
		*pfirst = *psecond;
		*psecond = tmp;
	}
}
