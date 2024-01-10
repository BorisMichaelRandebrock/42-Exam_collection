/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:48:07 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/04 19:26:10 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		range(int start, int end)
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

int     *ft_range(int start, int end)
{
	int	*ar;
//	int	r;
	int	i;

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
