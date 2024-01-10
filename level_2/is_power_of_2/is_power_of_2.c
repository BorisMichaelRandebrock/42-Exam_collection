/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:25:33 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 17:31:34 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
		if (n == 0)
				return (0);
		return (n & (n - 1)) == 0; 
}

int	main(int argc, char **argv)
{
		int		n;
		int		re;
		if (argc == 2)
		{
				n = atoi(argv[1]);	
				re = is_power_of_2(n);
				printf("one if is power of 2, 0 if not:  %i", re);
		}
		return (0);
}
