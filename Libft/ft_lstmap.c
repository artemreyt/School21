/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:51:58 by creicher          #+#    #+#             */
/*   Updated: 2019/09/19 19:09:48 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	head = f(lst);
	current = head;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (!current->next)
		{
			while (head)
			{
				current = head->next;
				free(head);
				head = current;
			}
			return (NULL);
		}
		current = current->next;
		current->next = NULL;
	}
	return (head);
}
