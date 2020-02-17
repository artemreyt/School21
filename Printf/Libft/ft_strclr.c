/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@studen.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 02:08:56 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/20 19:11:37 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			*s = '\0';
			++s;
		}
	}
}
