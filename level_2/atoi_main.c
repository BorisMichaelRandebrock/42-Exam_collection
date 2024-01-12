/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:43 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:34:53 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	int	num;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		printf("ft result:   %d\n", num);
		printf("orig result: %d\n", num);
	}
	return (0);
}
