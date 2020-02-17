/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:22:45 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 15:33:39 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FORMAT_H
# define PRINT_FORMAT_H

# include "flags_describer.h"

struct	s_print_info
{
	const char	*str;
	int			len;
	int			width;
	int			plus_found;
	int			hash_apply;
	int			num_of_zeros;
	char		fill_char;
};
typedef struct s_print_info	t_print_info;

int		print_decimal(t_buffer *buffer, const char *str,
					const t_fdescriber *describer);
int		print_bases(t_buffer *buffer, const char *str,
					const t_fdescriber *describer);
int		print_float(t_buffer *buffer, const char *str,
					const t_fdescriber *describer);
int		print_csp(t_buffer *buffer, char *str,
					const t_fdescriber *describer);

#endif
