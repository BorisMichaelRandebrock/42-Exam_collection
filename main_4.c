/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:33:43 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 18:24:34 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "today/ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

int	main(void)
{
		t_list	*lst;

		lst = malloc(sizeof(t_list));
		lst->data = ("Follow ");
		lst->next = malloc(sizeof(t_list));
		lst->next->data = ("the white ");
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = ("rabbit.");

		ft_list_foreach(lst, (void*) printf);
}
