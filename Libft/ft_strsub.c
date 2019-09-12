/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:39:06 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/11 14:46:23 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = ft_strnew(len);
	if (substr)
		ft_strncpy(substr, s + start, len);
	return (substr);
}
