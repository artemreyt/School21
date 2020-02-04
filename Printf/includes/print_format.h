/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:22:45 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/17 16:55:43 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FORMAT_H
# define PRINT_FORMAT_H

# include "flags_describer.h"

int			print_decimal(const char *str, const flags_describer *describer);
int			print_bases(const char *str, const flags_describer *describer);
int			print_float(const char *str, const flags_describer *describer);
int			print_csp(char *str, const flags_describer *describer);

#endif
