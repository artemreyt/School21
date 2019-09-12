/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:13:14 by creicher          #+#    #+#             */
/*   Updated: 2019/09/12 23:04:07 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char casted;
	char *result;

	result = NULL;
	casted = (char)c;
	while (*s)
	{
		if (*s == casted)
			result = (char *)s;
		s++;
	}
	return (casted == *s ? (char *)s : result);
}
