/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:43:02 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:38:57 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_foreach/ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
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
	t_list	*ls;

	ls = malloc(sizeof(t_list));
	ls->data = ("Follow ");
	ls->next = malloc(sizeof(t_list));
	ls->next->data = ("the white ");
	ls->next->next = malloc(sizeof(t_list));
	ls->next->next->data = ("Rabbit.");
	ft_list_foreach(ls, (void *)printf);
	return (0);
}
