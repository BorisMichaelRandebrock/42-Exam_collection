/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:27:15 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 10:36:36 by brandebr         ###   ########.fr       */
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
	(void)argc;
	(void)argv;
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
