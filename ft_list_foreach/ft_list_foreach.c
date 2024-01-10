/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:59:22 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 13:36:07 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
		t_list	*aux;

		aux = begin_list;
		while (aux)
		{
				(*f)(aux->data);
				aux = aux->next;
		}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
		t_list	*aux;
		t_list	*del;
		t_list	*prev;

		aux = *begin_list;
		prev = NULL;
		while (aux)
		{
				if ((*cmp)(aux->data, data_ref) == 0)
				{
						del = aux;
						if (prev == NULL)
								*begin_list = aux->next;
						else
								prev->next = aux->next;
						aux = aux->next;
						free(del);
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}

int		cmp(void *a, void *b)
{
		int	*n1 = (int *)a;
		int  *n2 = (int *)b;
		return (*n1 - *n2);
}

int		main(void)
{
		t_list	*lst;
		t_list	*ls;
		int		num[] = {12, 13, 12};
		int		del = 12; 

		lst = malloc(sizeof(t_list));
		lst->data = ("Follow the ");
		lst->next = malloc(sizeof(t_list));
		lst->next->data = ("white ");
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = ("Rabbi.\n");
		ft_list_foreach(lst, (void *)printf);
		ls = malloc(sizeof(t_list));
		ls->data = &num[0];
		ls->next = malloc(sizeof(t_list));
		ls->next->data = &num[1];
		ls->next->next = malloc(sizeof(t_list));
		ls->next->next->data = &num[2];
		lst = ls;
		while (ls)
		{
				printf("%i\n", *(int *)ls->data);
				ls = ls->next;
		}
		ls = lst;
		printf("new list with number removed:\n");
		ft_list_remove_if(&ls, &del, cmp);
		while (ls)
		{
				printf("%i\n", *(int *)ls->data);
				ls = ls->next;
		}
		while (ls)
		{
				printf("%d",*(int *)ls->data);
				ls = ls->next;
		}

		ft_list_foreach(ls, (void *)printf);
		return (0);
}
































/*
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
		t_list	*aux;

		aux = begin_list;
		while (aux)
		{
				(*f)(aux->data);
				aux = aux->next;
		}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
		t_list	*aux;
		t_list	*del;
		t_list	*prev;

		aux	= *begin_list;
		prev = NULL;
		while (aux)
		{
				if ((*cmp)(aux->data, data_ref) == 0)
				{
						del = aux;
						if (prev == NULL)
								*begin_list = aux->next;
						else
								prev->next = aux->next;
						aux = aux->next;						
				}
				else
				{
						prev = aux;
						aux = aux->next; 
				}
		}
}

int		cmp(void *u, void *d)
{
		int		*a = (int *)u;
		int		*b = (int *)d;
		return (*a - *b);
}

int		main(void)
{
		t_list	*lst;
		t_list	*l;
		int		num[] =  {5, 13, 5};
		int		del = 5;

		lst = malloc(sizeof(t_list));
		lst->data = ("Follow ");
		lst->next = malloc(sizeof(t_list));
		lst->next->data = ("the ");
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = ("white ");
		lst->next->next->next = malloc(sizeof(t_list));
		lst->next->next->next->data = ("Rabbi.");
		ft_list_foreach(lst, (void*)printf);
		l = malloc(sizeof(t_list));
		l->data = &num[0];
		l->next = malloc(sizeof(t_list));
		l->next->data = &num[1];
		l->next->next = malloc(sizeof(t_list));
		l->next->next->data = &num[2];
		while (l)
		{
				printf("%d",*(int *)l->data);
				l = l->next;
		}
		printf("\n");
		ft_list_remove_if(&l, &del, cmp);
		while (l)
		{
				printf("%d",*(int *)l->data);
				l = l->next;
		}
		return (0);
}
*/











































/*

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
		t_list	*aux;

		aux = begin_list;
		while (aux)
		{
				if (aux->data)
					(*f)(aux->data);
				aux = aux->next;
		}
}


int	main(void)
{
		t_list	*lst;

		lst = malloc(sizeof(t_list));
		lst->data = ("Follow ");
		lst->next =(t_list*) malloc(sizeof(t_list));
		lst->next->data = ("the ");
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = ("white ");
		lst->next->next->next  = malloc(sizeof(t_list));
		lst->next->next->next->data = ("rabbi");
		lst->next->next->next->next = malloc(sizeof(t_list));
		lst->next->next->next->next->data = (".");
		ft_list_foreach(lst, (void *)printf);
		printf("\n");
	return (0);
}

*/





























		/*void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
		t_list	*lst;

		lst = begin_list;
		while (lst)
		{
				if (lst->data)
				{
						(*f)(lst->data);
				}
				lst = lst->next;
		}
}

t_list	*ft_new_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*test_list;

	test_list = ft_new_elem("Follow ");
	test_list->next = ft_new_elem("the ");
	test_list->next->next = ft_new_elem("white ");
	test_list->next->next->next = ft_new_elem("rabbit");
	test_list->next->next->next->next = ft_new_elem(".");
	ft_list_foreach(test_list, (void *)printf);
	printf("\n");
	return (0);
}
*/
