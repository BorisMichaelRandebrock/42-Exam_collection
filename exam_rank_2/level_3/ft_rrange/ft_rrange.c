/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:28:18 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 18:52:51 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	range(int start, int end)
{
	int	c;

	c = 0;
	if (start < end)
	{
		while (start <= end)
		{
			c++;
			start++;
		}
	}
	else
	{
		while (end <= start)
		{
			end++;
			c++;
		}
	}
	return (c);
}

int	*ft_rrange(int start, int end)
{
	int	*ar;
	int	r;
	int	i;

	r = range(start, end);
	i = 0;
	ar = malloc(sizeof(int *) * (r));
	while (i < r)
	{
		if (start < end)
		{
			ar[i] = end;
			i++;
			end--;
		}
		else
		{
			ar[i] = end;
			i++;
			end++;
		}
	}
	return (ar);
}
