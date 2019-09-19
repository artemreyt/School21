/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:32:42 by creicher          #+#    #+#             */
/*   Updated: 2019/09/18 15:01:09 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *after, t_list *link)
{
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		if (current == after)
		{
			if (current == *lst)
				ft_lstadd(lst, link);
			else
			{
				current = after->next;
				after->next = link;
				link->next = current;
			}
		}
	}
}
