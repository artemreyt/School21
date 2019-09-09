/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:11:04 by creicher          #+#    #+#             */
/*   Updated: 2019/09/09 18:38:44 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_CTYPE_H
# define FT_CTYPE_H

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isprint(int c);
int 	ft_toupper(int c);
int 	ft_tolower(int c);

#endif