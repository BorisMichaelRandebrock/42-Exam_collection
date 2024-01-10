/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:49:40 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/04 19:14:52 by brandebr         ###   ########.fr       */
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
		(void)argc;

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
