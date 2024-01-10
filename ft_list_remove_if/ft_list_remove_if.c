/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:17:06 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/09 09:33:31 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
/*
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
						free(del);
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}*/
/*
int cmp_func(int *a, int *b) 
{
    return *a - *b;
}

int main(void)
{
    t_list *lst = malloc(sizeof(t_list));

	lst->data = malloc(sizeof(int)), *(int *)(lst->data) = 42;
    lst->next = malloc(sizeof(t_list));
    lst->next->data = malloc(sizeof(int)), *(int *)(lst->next->data) = 17;
    lst->next->next = malloc(sizeof(t_list));
    lst->next->next->data = malloc(sizeof(int)), *(int *)(lst->next->next->data) = 42;
	int	data_ref = 42;
    ft_list_remove_if(&lst, &data_ref , cmp_func);

	while (lst)
	{
			printf("%i", *(int*)lst->data);
			lst = lst->next;
	}
		
    for (t_list *temp = lst; temp; temp = temp->next)
        printf("%d ", *(int *)(temp->data));
    printf("\n");

    while (lst)
    {
        t_list *temp = lst->next;
        free(lst->data), free(lst);
        lst = temp;
    }

    return 0;
}
*/
/*
int main(void)
{
    // Create a simple linked list
    t_list *lst = malloc(sizeof(t_list));
    lst->data = malloc(sizeof(int));
    *(int *)(lst->data) = 42;

    lst->next = malloc(sizeof(t_list));
    lst->next->data = malloc(sizeof(int));
    *(int *)(lst->next->data) = 17;

    lst->next->next = malloc(sizeof(t_list));
    lst->next->next->data = malloc(sizeof(int));
    *(int *)(lst->next->next->data) = 42;

    // Print the list before removal
    t_list *temp = lst;
    while (temp)
    {
        printf("%d ", *(int *)(temp->data));
        temp = temp->next;
    }
    printf("\n");

    // Remove nodes with data equal to 42
    int data_ref = 42;
    ft_list_remove_if(lst->data, &data_ref, cmp_func);

    // Print the list after removal
    temp = lst;
    while (temp)
    {
        printf("%d ", *(int *)(temp->data));
        temp = temp->next;
    }
    printf("\n");

    // Free the allocated memory
    while (lst)
    {
        t_list *temp = lst->next;
        free(lst->data);
        free(lst);
        lst = temp;
    }

    return 0;
}

*/






































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
						free(del);
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}






































/*

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
						free(del);
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}

*/

































/*
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
		t_list	*aux;
		t_list	*tmp;
		t_list	*prev;

		prev = NULL;
		aux = *begin_list;
		while (aux)
		{
				if ((*cmp)(aux->data, data_ref) == 0)
				{
						tmp = aux;
						if (prev == NULL)
								*begin_list = aux->next;
						else
								prev->next = aux->next;
						aux = aux->next;
						free(tmp);
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}
*/

int compare_data(void *a, void *b) {
		// You can define your own comparison logic here
		// For this example, we'll compare integers
		int *int_a = (int *)a;
		int *int_b = (int *)b;
		return (*int_a - *int_b);
}

int main() {
		// Create a sample linked list
		t_list *list = NULL;
	int data[] = {30, 30, 10, 20, 30, 40, 30, 50, 30, 30};
//		int data[] = {20, 20, 30};

		for (unsigned long i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
				t_list *new_node = (t_list *)malloc(sizeof(t_list));
				new_node->data = &data[i];
				new_node->next = list;
				list = new_node;
		}

		// Display the initial linked list
		printf("Initial Linked List: ");
		t_list *current = list;
		while (current != NULL) {
				printf("%d -> ", *((int *)current->data));
				current = current->next;
		}
		printf("NULL\n");

		// Define the condition for removal
		int target = 30;

		// Remove elements matching the condition
		ft_list_remove_if(&list, &target, compare_data);

		// Display the modified linked list
		printf("Modified Linked List: ");
		current = list;
		while (current != NULL) {
				printf("%d -> ", *((int *)current->data));
				current = current->next;
		}
		printf("NULL\n");

		// Free memory (not shown in this example, but it's important to free allocated memory)

		return 0;
}
