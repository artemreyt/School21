/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:51:58 by creicher          #+#    #+#             */
/*   Updated: 2019/09/13 20:08:00 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	head = f(lst);
	current = head;
	while (lst->next)
	{
		t_list	*new;

		lst = lst->next;
		new = f(lst);
		if (!new)
		{
			ft_lstdel(&head, ft_memdel);
			break;
		}
		current->next = new;
		current = new;
		current->next = NULL;
	}
	return (head);
}
*/
