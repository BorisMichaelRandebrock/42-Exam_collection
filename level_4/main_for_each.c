/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_each.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:43:02 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 15:09:46 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./ft_foreach/ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int		cmp(void	*a, void	*b)
{
		int	*aa = (int *)a;
		int *bb = (int *)b;

		return (*aa - *bb);
}


int	main(void)
{
		t_list	*ls;
		t_list	*l;
		int		num[] = {5, 13, 5, 11, 10, 9, 8, 7};
		int		target = 5;

		ls = malloc(sizeof(t_list));
		ls->data = ("Follow ");
		ls->next = malloc(sizeof(t_list));
		ls->next->data = ("the white ");
		ls->next->next = malloc(sizeof(t_list));
		ls->next->next->data = ("Rabbi.");
		ft_list_foreach(ls, (void *)printf);
		printf("\n");
		l = malloc(sizeof(t_list));
		l->data = &num[0];
		l->next = malloc(sizeof(t_list));
		l->next->data = &num[1];
		l->next->next = malloc(sizeof(t_list));
		l->next->next->data = &num[2];
		ft_list_foreach(l, (void *)printf);
		ls = l;
		while (l)
		{
				printf("%i\n", *(int*)l->data);
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

