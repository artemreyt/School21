/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:44:13 by creicher          #+#    #+#             */
/*   Updated: 2019/09/19 19:09:42 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void const *content, size_t size)
{
	while (lst)
	{
		if (ft_memcmp(lst->content, content, size) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
