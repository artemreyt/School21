/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 06:15:48 by ecathryn          #+#    #+#             */
/*   Updated: 2019/09/26 07:12:45 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node != NULL)
	{
		node->next = NULL;
		if (content != NULL && content_size != 0)
		{
			node->content_size = content_size;
			node->content = malloc(content_size);
			if (node->content != NULL)
				ft_memcpy(node->content, content, content_size);
			else
			{
				free(node);
				node = NULL;
			}
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
	}
	return (node);
}
