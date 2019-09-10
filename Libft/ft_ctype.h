/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:11:04 by creicher          #+#    #+#             */
/*   Updated: 2019/09/10 10:53:04 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_CTYPE_H
# define FT_CTYPE_H

#include <string.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isprint(int c);
int 	ft_toupper(int c);
int 	ft_tolower(int c);

#endif