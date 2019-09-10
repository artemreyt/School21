/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:24:11 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 12:21:12 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);
void 	ft_putstr(const char *str);
void	ft_putnbr(size_t n);

#endif