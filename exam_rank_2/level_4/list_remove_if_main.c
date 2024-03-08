/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove_if_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:43:02 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:52:28 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_foreach/ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int	cmp(void *a, void *b)
{
	int	*aa;
	int	*bb;

	aa = (int *)a;
	bb = (int *)b;
	return (*aa - *bb);
}

int	main(void)
{
	t_list	*l;
	t_list	*ls;
	int		num[] = {5, 13, 5, 11, 10, 9, 8, 5};
	int		target;

	target = 5;
	printf("\n");
	l = malloc(sizeof(t_list));
	l->data = &num[0];
	l->next = malloc(sizeof(t_list));
	l->next->data = &num[1];
	l->next->next = malloc(sizeof(t_list));
	l->next->next->data = &num[2];
	l->next->next->next = malloc(sizeof(t_list));
	l->next->next->next->data = &num[3];
	l->next->next->next->next = malloc(sizeof(t_list));
	l->next->next->next->next->data = &num[4];
	l->next->next->next->next->next = malloc(sizeof(t_list));
	l->next->next->next->next->next->data = &num[5];
	l->next->next->next->next->next->next = malloc(sizeof(t_list));
	l->next->next->next->next->next->next->data = &num[6];
	l->next->next->next->next->next->next->next = malloc(sizeof(t_list));
	l->next->next->next->next->next->next->next->data = &num[7];
	ls = l;
	while (l)
	{
		printf("%i\n", *(int *)l->data);
		l = l->next;
	}
	l = ls;
	ft_list_remove_if(&l, &target, cmp);
	printf("new ordered list: \n");
	while (l)
	{
		printf("%i\n", *(int *)l->data);
		l = l->next;
	}
	return (0);
}
