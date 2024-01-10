/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:54:41 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 18:09:55 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len);

int		main(int argc, char **argv)
{
		(void) argv;
		int		numbs[] = {13, 5, 6, 12};
		int		res;
		if (argc == 2)
		{
				res = max(numbs, 4);
				printf("max number: %i\n",  res);
		}
		return (0);
}
