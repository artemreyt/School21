/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:15:27 by creicher          #+#    #+#             */
/*   Updated: 2019/09/18 14:25:36 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback(t_list *lst, void const *content, size_t size)
{
	t_list	*new;

	if (!lst)
		return ;
	lst = ft_lstend(lst);
	new = ft_lstnew(content, size);
	lst->next = new;
}
