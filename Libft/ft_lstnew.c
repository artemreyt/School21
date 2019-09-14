/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:20:27 by creicher          #+#    #+#             */
/*   Updated: 2019/09/14 13:25:56 by artemstarshov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new)
	{
		// new->content = malloc(content_size);
		// if (new->content)
		// {
		// 	if (content)
		// 	{
		// 		ft_memcpy(&new->content, content, content_size);
		// 		new->content_size = content_size;
		// 	}
		// 	else
		// 	{
		// 		new->content = NULL;
		// 		new->content_size = 0;
		// 	}
		// 	new->next = NULL;
		// }
		// else
		// 	free(new);
		new->content = (void *)content;
		if (!new->content)
			new->content_size = 0;
		else
			new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
