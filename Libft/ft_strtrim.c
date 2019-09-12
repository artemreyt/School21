/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:06:05 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/11 16:11:42 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*whitespaces = " \t\n";
	
	start = 0;
	while (ft_strchr(whitespaces, (int)s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (ft_strchr(whitespaces, (int)s[end]))
		end--;
	return (ft_strsub(s, start, end - start + 1));
}