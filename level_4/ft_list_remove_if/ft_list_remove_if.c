/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:57:33 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:47:47 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_foreach/ft_list.h" // Read the assignement with attention.
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
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
