/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:22:18 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 14:23:27 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n);

int	main(int argc, char **argv)
{
	int	n;
	int	re;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		re = is_power_of_2(n);
		printf("one if is power of 2, 0 if not:  %i", re);
	}
	return (0);
}
