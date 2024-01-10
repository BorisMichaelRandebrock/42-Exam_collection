/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:29:59 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 19:00:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "today/list.h"
#include <stdio.h>
#include <stdlib.h>
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

int	cmp(int a, int b)
{
		if (a <= b)
				return (1);
		else
				return (0);
}

int	main(void)
{
		t_list	*lst;
		t_list	*ls;

		lst = malloc(sizeof(t_list));
		lst->data = 14;
		lst->next = malloc(sizeof(t_list));
		lst->next->data = 13;
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = 12;
		ls = lst;
		while (lst)
		{
				printf("%i\n", lst->data);
				lst = lst->next;
		}
		printf("ordered list:\n");
		lst = ls;
		sort_list(lst, cmp);
		while (lst)
		{
				printf("%i\n", lst->data);
				lst = lst->next;
		}
		return (0);
}
