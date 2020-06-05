/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:51:45 by artemstarsh       #+#    #+#             */
/*   Updated: 2019/09/15 21:22:01 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_putchar_fd(char c, int fd)
{
	unsigned char	casted;

	casted = (unsigned char)c;
	return (write(fd, &casted, 1));
}
