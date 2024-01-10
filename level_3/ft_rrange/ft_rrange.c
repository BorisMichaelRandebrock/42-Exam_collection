/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:28:18 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/22 12:47:32 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		range(int start, int end)
{
		int		c;

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

int     *ft_rrange(int start, int end)
{
		int		*ar;
		int		r = range(start, end);
		int		i;

		i = 0;
		ar = malloc(sizeof(int *) * (r ));
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

