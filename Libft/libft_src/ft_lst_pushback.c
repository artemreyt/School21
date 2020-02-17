/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:15:27 by creicher          #+#    #+#             */
/*   Updated: 2019/11/13 15:56:54 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback(t_list **lst, void const *content, size_t size)
{
	t_list	*new;
	t_list	*end;

	if (!(*lst))
		*lst = ft_lstnew(content, size);
	else
	{
		end = ft_lstend(*lst);
		new = ft_lstnew(content, size);
		end->next = new;
	}
}
