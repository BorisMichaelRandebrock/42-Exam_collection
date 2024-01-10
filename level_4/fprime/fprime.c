/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:04:37 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 16:23:15 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
		int		i;

		i = 1;
		if (n == 1)
		{
				printf("1");
				return ;
		}
		while (i++ <= n)
		{
				if (i == n)
						printf("%d", i);
				else
				{
						if (n % i == 0)
						{
								printf("%i*", i);
								n /= i;
								i = 1;
						}
				}
		//		i++;
		}
		return ;
}

int	main(int argc, char **argv)
{
		if (argc == 2)
		{
				int		num;
				num = atoi(argv[1]);
				fprime(num);
		}
		printf("\n");
		return (0);
}
