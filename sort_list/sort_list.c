/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:42:31 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/21 13:34:27 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int		cmp(int a, int b)
{
		if (a > b)
				return (0);
		return (1);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
		t_list	*start;
		int		swap;

		start = lst;
		while (lst->next)
	 	{
			if ((*cmp)(lst->data, lst->next->data) == 0)
				{
						swap = lst->data;
						lst->data = lst->next->data;
						lst->next->data = swap;
						lst = start;
				}
				else
						lst = lst->next;
		}
		lst = start;
		return (lst);
}

int	main(void)
{
		t_list *l;

		l = malloc(sizeof(t_list));
		l->data = (13);
		l->next = malloc(sizeof(t_list));
		l->next->data = (12);
		l->next->next = malloc(sizeof(t_list));
		l->next->next->data = (11);
//		sort_list(l, cmp);
		while (l)
		{
				printf("%d\n", l->data);
				l = l->next;
		}
		return (0);
}







/*
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
		t_list	*start;
		int		swap;

		start = lst;
		while (lst->next)
		{
				if	((*cmp)(lst->data, lst->next->data) == 0)
				{
						swap = lst->data;
						lst->data = lst->next->data;
						lst->next->data = swap;
						lst = start;
				}
				else
						lst = lst->next;
		}
		lst = start; 
		return (lst);
}

int		main(void)
{
			t_list *ls;
			int     numbs[] = {13, 13 ,12};		
		
			ls = malloc(sizeof(t_list));
          ls->data = numbs[0];
           ls->next = malloc(sizeof(t_list));
           ls->next->data = numbs[1];
           ls->next->next = malloc(sizeof(t_list));
           ls->next->next->data = numbs[2];
		   sort_list(ls, cmp);
		   while (ls)
		   {
				   printf("%d\n", ls->data);
				   ls = ls->next;
		   }
		   return (0);
}

*/





































/*
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
		int		swap;
		t_list	*start;

		start = lst;
		while (lst->next)
		{
				if ((*cmp)(lst->data, lst->next->data) == 0)
				{
						swap = lst->data;
						lst->data = lst->next->data;
						lst->next->data = swap;
						lst = start;
				}
				else
						lst =  lst->next;
		}
		lst = start;
		return (lst);
}

int compare_data(void *a, void *b) {
		int *int_a = (int *)a;
		int *int_b = (int *)b;
		if (int_a > int_b)
				return (0);
		return (1);
}

int main(void)
{
		t_list *list = NULL;
		int data[] = {30, 30, 10, 20, 30, 40, 30, 50, 30, 30};

		for (unsigned long i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
				t_list *new_node = (t_list *)malloc(sizeof(t_list));
				new_node->data = data[i];
				new_node->next = list;
				list = new_node;
		}
		printf("Initial Linked List: ");
		t_list *current = list;
		while (current != NULL) 
		{
				printf("%d -> ", ((int )current->data));
				current = current->next;
		}
		printf("NULL\n");
		sort_list(list, (void *)compare_data);
		printf("Modified Linked List: ");
		current = list;
		while (current != NULL) 
		{
				printf("%d -> ", ((int )current->data));
				current = current->next;
		}
		printf("NULL\n");
		return 0;
}*/
