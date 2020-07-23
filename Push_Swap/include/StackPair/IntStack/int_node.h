/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_node.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:52:48 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 11:53:26 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_NODE_H
# define INT_NODE_H

struct						s_int_node
{
	int					value;
	struct s_int_node	*prev;
	struct s_int_node	*next;
};

typedef struct s_int_node	t_int_node;

t_int_node					*create_int_node(int value);

#endif
