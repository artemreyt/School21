/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 02:44:05 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/14 03:12:35 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_describer.h"
#include "libft.h"
#include <stdio.h>

void print_flags(t_list *lst) {
	while (lst) {
		printf("%d ", *((e_flags *)lst->content));
		lst = lst->next;
	}
	printf("\n");
}

void	print_flag_describer(const flags_describer *describer) {
	printf("FLAGS:\nwidth: %d\n", describer->width);
	printf("precision: %s %d\n", (describer->precision.found ? "found" : "not found"), describer->precision.value);
	printf("flags: ");
	print_flags(describer->flags);
	printf("\n");
}


int main() {
	char *str = (char *)malloc(200);
	scanf("%s", str);
	flags_describer *describer = find_flags(&str);
	print_flag_describer(describer);
	// free(str);
	return (0);
}
