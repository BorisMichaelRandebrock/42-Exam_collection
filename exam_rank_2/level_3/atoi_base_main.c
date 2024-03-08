/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:47 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/05 16:26:36 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base);

int	main(int argc, char **argv)
{
	int	num;
	int	num2;

	if (argc == 3)
	{
		num = ft_atoi_base(argv[1], atoi(argv[2]));
		num2 = atoi(argv[1]);
		printf("%i\n %i\n", num, num2);
	}
}
