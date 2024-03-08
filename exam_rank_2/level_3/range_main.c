/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:49:40 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/08 16:25:58 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end);
int		range(int start, int end);

int	main(int argc, char **argv)
{
		int	start;
		int	end;
		int	ran;
		int	*res;
		int i = 0;

		if (argc < 3 || argc > 3)
		{
			printf("please enter 2 numbers");
			return (1);
		}
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		ran = range(start, end);
		printf("the range is: %d\n", ran);
		res = ft_range(start, end);
		while (i <= ran -1)
		{
				printf("%d ---- i %d\n", res[i], i);
				i++;
		}
		printf("\n");
}
