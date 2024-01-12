/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:25:08 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:23:52 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

void	flood(char **tab, t_point size, int x, int y, char to_fill)
{
	if (x < 0 || y < 0)
		return ;
	if (x == size.x || y == size.y)
		return ;
	if (tab[y][x] != to_fill)
		return ;
	if (tab[y][x])
		tab[y][x] = 'F';
	flood(tab, size, x + 1, y, to_fill);
	flood(tab, size, x - 1, y, to_fill);
	flood(tab, size, x, y + 1, to_fill);
	flood(tab, size, x, y - 1, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int		x;
	int		y;
	char	to_fill;

	x = begin.x;
	y = begin.y;
	to_fill = tab[y][x];
	flood(tab, size, x, y, to_fill);
}
