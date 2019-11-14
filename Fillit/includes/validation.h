/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:04:27 by creicher          #+#    #+#             */
/*   Updated: 2019/11/14 17:24:19 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "libft.h"
# include "tetramino.h"

# define MAX_TETRAMINOS_NUMBER 26
# define MIN_TOUCHES 6

void	exit_with_error(t_list **tetralist);
int		check_valid_block(char *char_tetramino);

#endif
