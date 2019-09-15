/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:51:58 by creicher          #+#    #+#             */
/*   Updated: 2019/09/15 21:49:04 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;
	t_list	*new;

	head = f(lst);
	current = head;
	while (lst->next)
	{
		lst = lst->next;
		new = f(lst);
		if (!new)
		{
			while (head)
			{
				current = head->next;
				free(head);
				head = current;
			}
			return (NULL);
		}
		current->next = new;
		current = new;
		current->next = NULL;
	}
	return (head);
}
