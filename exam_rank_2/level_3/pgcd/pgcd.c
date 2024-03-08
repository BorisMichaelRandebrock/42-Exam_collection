/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:41:12 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 19:02:32 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int	i;

	i = 0;
	if (a > b)
		i = b;
	else
		i = a;
	while (i)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("%i", i);
			return (i);
		}
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;

	if (argc == 3)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		pgcd(n1, n2);
	}
	printf("\n");
	return (0);
}
