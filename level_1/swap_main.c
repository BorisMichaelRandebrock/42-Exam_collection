/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:10:42 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:34:47 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	printf("a: %d, b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);
	return (0);
}
