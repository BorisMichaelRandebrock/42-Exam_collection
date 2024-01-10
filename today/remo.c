/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:02 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 17:29:30 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
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
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}

