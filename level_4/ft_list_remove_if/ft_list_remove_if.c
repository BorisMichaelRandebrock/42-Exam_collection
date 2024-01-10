/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:57:33 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/09 11:23:06 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_foreach/ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
		t_list	*aux;
		t_list	*del;
		t_list	*prev;

		aux = *begin_list;
		prev = NULL;
		while (aux)
		{
				if ((cmp)(aux->data, data_ref) == 0)
				{
						del = aux;
						if (prev == 0)
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
