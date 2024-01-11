/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:48:07 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 18:50:40 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	range(int start, int end)
{
	int	r;

	r = 0;
	if (start < end)
	{
		while (start <= end)
		{
			r++;
			start++;
		}
	}
	else
	{
		while (end <= start)
		{
			r++;
			end++;
		}
	}
	return (r);
}

int	*ft_range(int start, int end)
{
	int	*ar;
	int	i;

	//	int	r;
	i = 0;
	//	r = range(start, end);
	//	r = abs((start - end)) + 1;
	ar = malloc(sizeof(int) * (abs((start - end)) + 1));
	if (start == end)
	{
		ar[0] = start;
		return (ar);
	}
	else if (start < end)
	{
		while (start <= end)
		{
			ar[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (end <= start)
		{
			ar[i] = start;
			start--;
			i++;
		}
	}
	return (ar);
}
