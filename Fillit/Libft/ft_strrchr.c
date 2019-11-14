/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:13:14 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:35:09 by creicher         ###   ########.fr       */
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
