/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 00:33:55 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/01 00:38:49 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	if (lst && *lst)
	{
		prev = *lst;
		curr = prev->next;
		if (curr)
		{
			prev->next = 0;
			next = curr->next;
			while (next)
			{
				curr->next = prev;
				prev = curr;
				curr = next;
				next = curr->next;
			}
			curr->next = prev;
			*lst = curr;
		}
	}
}
