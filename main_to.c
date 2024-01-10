/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:24:21 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 17:31:07 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "today/ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int	cmp(void *ab, void *ba)
{
		int		*a = (int *)ab;
		int		*b = (int *)ba;
		
		return (*a - *b);
}

int	main(void)
{
		t_list	*lst;
		t_list	*aux;
		int		num[] = {13, 5, 13};
		int target = 5;

		lst = malloc(sizeof(t_list));
		lst->data = &num[0];
		lst->next = malloc(sizeof(t_list));
		lst->next->data = &num[1];
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = &num[2];
		aux = lst;
		while (lst)
		{
				printf("->%i\n",*(int*) lst->data);
				lst = lst->next;
		}
		lst = aux;
		printf("new list: \n");
		ft_list_remove_if(&lst, &target, cmp); 
		while (lst)
		{
				printf("->%i\n",*(int*) lst->data);
				lst = lst->next;
		}
		return (0);
}
