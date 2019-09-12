/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:10:56 by creicher          #+#    #+#             */
/*   Updated: 2019/09/12 23:26:04 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	// if (size)
	// {
	// 	size_t i;

	// 	i = 0;
	// 	while (i < size && dst[i])
	// 		i++;
	// 	while (i < size - 1 && *src)
	// 		dst[i++] = *src++;
			
	// 	dst[i] = '\0';
	// }
	// return (ft_strlen(dst));

	size_t	i;
	int		is_terminated;

	is_terminated = 0;
	i = ft_strlen(dst);
	while (i < size)
	{
		dst[i] = *src;
		if (*src == '\0')
		{
			is_terminated = 1;
			break;
		}
		i++;
		src++;
	}
	if (!is_terminated)
		dst[size - 1] = '\0';
	
	return (i);
}

// int main()
// {
// 	char str[20] = "gghv";
// 	ft_strlcat(str, "hghfj", 20);
// 	ft_putendl(str);
// }
