/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:18:48 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/07 14:14:47 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int		max(int* tab, unsigned int len)
{
		unsigned int	i;
		int	max;

		max = tab[0];
		i = 0;
		while (i < len)
		{
				if (max < tab[i])
						max = tab[i];
				i++;
		}
		return (max);
}

int		main(void)
{
		int		ar[] = {5, 35, 94};
		printf("the max number is: %i",max(ar, 3));
		return (0);
}








































/*		
int		max(int* tab, unsigned int len)
{
		unsigned int	i;
		int		max;

		i = 0;
		max = tab[0];
		while (i < len)
		{
				if (max < tab[i])
				{
						max = tab[i];
				}
				i++;
		}
		return (max);
}

int		main(void)
{
		int	ar[] = {25, 5, 35};

		printf("the highest number is: %i\n",max(ar, 3));
		return (0);
}

*/



































/*
 
int		max(int* tab, unsigned int len)
{
		int		max;

		max = tab[0];
		if (len == 0)
				return (0);
		while (len--)
		{
				if (max < tab[len])
						max = tab[len];
		}
		return (max);
}

int		main(void)
{
		int		ar[] = {-90, -500, -6000};
		printf("%i", max(ar, 3));
		return (0);
}

 */




























/*
int		max(int* tab, unsigned int len)
{
		int		max;

		max = 0;
		if (len == 0)
				return (0);
		while (len--)

		{
				if (max < tab[len])
						max = tab[len];
		}
		return (max);
}

int main(void)
{
		int ar[] = {}; 
		
		printf("%i", max(ar, 0));
		return (0);
}



*/

































/*
int		max(int* tab, unsigned int len) {
{
		unsigned int		i;
		int		max;

		i = 0;
		max = 0;
		if (len == 0)
				return (0); 
		while (i < len)
		{
				if (max < tab[i])
						max = tab[i];
				i++;
		}
		
		int	max;

		max = tab[0];
		if (len == 0)
				return (0); 
		len--;
		while (len)
		{
				if (max < tab[len])
						max = tab[len];
				len--;
		}
		return (max);
}

int	main(void)
{
		int	ar[3] = {990, 3, 190};

//		ar[0] = 1;
//		ar[1] = 3;
//		ar[2] = 4;
		printf("%i", max(ar, 3));
		return (0);
} */
