/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:09:49 by creicher          #+#    #+#             */
/*   Updated: 2019/09/14 13:04:11 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (s1[i])
		i++;
	while (n && *s2)
	{
		s1[i++] = *s2++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
