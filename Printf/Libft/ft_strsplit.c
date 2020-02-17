/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 07:26:54 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/25 07:28:55 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	delim[2];

	delim[0] = c;
	delim[1] = '\0';
	return (ft_strdsplit(s, delim));
}
