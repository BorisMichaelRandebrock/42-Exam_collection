/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:27:15 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/22 12:47:45 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     *ft_rrange(int start, int end);
int		range(int start, int end);
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
		int		*res;
		int i = 0;

		(void)argc;
		(void)argv;
		int		start = atoi(argv[1]);
		int		end = atoi(argv[2]);
		int size = range(start, end);
		res = ft_rrange(start, end);
		while (i < size)
		{
				printf("%i\n", res[i]);
				i++;
		}
		return (0);
}
