/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:54:41 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 14:40:00 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len);

int	main(int argc, char **argv)
{
	int	numbs[] = {13, 5, 6, 42, 12};
	int	res;

	(void)argv;
	if (argc == 1)
	{
		res = max(numbs, 5);
		printf("max number: %i\n", res);
	}
	return (0);
}
