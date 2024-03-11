/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:27:15 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/08 16:37:03 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_rrange(int start, int end);
int	range(int start, int end);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	*res;
	int	i;
	int	start;
	int	end;
	int	size;

	i = 0;
	if (argc < 3 || argc > 3)
	{
		printf("please enter 2 numbers");
		return (1);
	}
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	size = range(start, end);
	res = ft_rrange(start, end);
	while (i < size)
	{
		printf("%i\n", res[i]);
		i++;
	}
	return (0);
}
