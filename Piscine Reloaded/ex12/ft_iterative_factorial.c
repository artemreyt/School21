/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:04:49 by creicher          #+#    #+#             */
/*   Updated: 2019/09/06 20:06:16 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;

	if (nb < 0 || nb >= 13)
		return (0);
	result = 1;
	while (nb > 0)
		result *= nb--;
	return (result);
}
