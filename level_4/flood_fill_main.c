/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:20:14 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:23:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./flood_fill/flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

void	flood_fill(char **tab, t_point size, t_point begin);

char	**make_area(char **zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

int	main(void)
{
	t_point	size;
	char	**area;
	t_point	begin;

	// size = {8, 5};
	size.x = 8;
	size.y = 5;
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	// begin = {7, 4}; //not working like this on vsc
	begin.x = 7;
	begin.y = 4;
	// begin.x = 2;//checking changing 0 to F - comment other borders 👆🏻
	// begin.y = 2;
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
