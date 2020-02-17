/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 07:38:52 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/26 08:28:04 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_lstcontdel(void *content, size_t content_size)
{
	if (content_size != 0)
	{
		free(content);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*curr;

	first = NULL;
	if (f != NULL && lst != NULL)
	{
		first = f(lst);
		curr = first;
		lst = lst->next;
		while (lst != NULL)
		{
			if (curr == NULL)
			{
				ft_lstdel(&first, ft_lstcontdel);
				break ;
			}
			curr->next = f(lst);
			curr = curr->next;
			lst = lst->next;
		}
	}
	return (first);
}
