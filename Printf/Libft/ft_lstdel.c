/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:41:29 by creicher          #+#    #+#             */
/*   Updated: 2020/01/04 00:14:14 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	if (!alst || !(*alst) || !del)
		return ;
	current = *alst;
	while (current)
	{
		next = (current)->next;
		ft_lstdelone(&current, del);
		current = next;
	}
	*alst = NULL;
}
