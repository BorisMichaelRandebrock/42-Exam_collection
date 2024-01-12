/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:10:40 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:10:35 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size);

int	main(void)
{
	int	ns[] = {5, 3, 7, 5, 9, 10, 9, 2};
	int	i;
	int	size;

	size = 8;
	i = 0;
	while (i < size)
	{
		printf("%d\n", ns[i]);
		i++;
	}
	i = 0;
	sort_int_tab(ns, size);
	printf("new ordered tab\n");
	while (i < size)
	{
		printf("%d\n", ns[i]);
		i++;
	}
	return (0);
}
