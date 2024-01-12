/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:41:36 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:35:29 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_list_size/ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list);

int	main(void)
{
	t_list	*list;
	int		size;

	list = malloc(sizeof(t_list));
	list->next = malloc(sizeof(t_list));
	list->next->next = malloc(sizeof(t_list));
	list->next->next->next = malloc(sizeof(t_list));
	list->next->next->next->next = malloc(sizeof(t_list));
	list->data = "1";
	list->next->data = "2";
	list->next->next->data = "3";
	list->next->next->next->data = "4";
	list->next->next->next->next->data = "5";
	size = ft_list_size(list);
	printf("size: %i\n", size);
	return (0);
}
