/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:13:32 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

int	cmp(int a, int b)
{
	if (a > b)
		return (0);
	return (1);
}

int	main(void)
{
	t_list	*ls;
	t_list	*l;

	ls = malloc(sizeof(t_list));
	ls->data = (13);
	ls->next = malloc(sizeof(t_list));
	ls->next->data = (12);
	ls->next->next = malloc(sizeof(t_list));
	ls->next->next->data = (10);
	l = ls;
	while (ls)
	{
		printf("%i\n", ls->data);
		ls = ls->next;
	}
	ls = l;
	sort_list(ls, cmp);
	printf("after sort_list: \n");
	while (ls)
	{
		printf("%i\n", ls->data);
		ls = ls->next;
	}
	return (0);
}
/*
 int	main(void)
{
		t_list *l;

		l = malloc(sizeof(t_list));
		l->data = (13);
		l->next = malloc(sizeof(t_list));
		l->next->data = (12);
		l->next->next = malloc(sizeof(t_list));
		l->next->next->data = (11);
		sort_list(l, cmp);
		while (l)
		{
				printf("%d\n", l->data);
				l = l->next;
		}
		return (0);
}
*/
