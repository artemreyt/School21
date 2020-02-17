/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecathryn <ecathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 00:58:17 by ecathryn          #+#    #+#             */
/*   Updated: 2020/02/01 01:06:15 by ecathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(const t_list *lst, size_t pos)
{
	size_t	i;

	i = 0;
	while (lst && i < pos)
	{
		lst = lst->next;
		i++;
	}
	return ((t_list*)lst);
}
