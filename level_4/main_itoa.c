/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:21:08 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 17:23:38 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		nc(int nbr);
char	*ft_itoa(int nbr);

int	main(int argc, char ** argv)
{
		if (argc == 2)
		{
			int	nu = atoi(argv[1]);
			int ns = nc(nu);
			printf("the numbers found in the number introduced are totalling:\n %d\n", ns);
			char *new = ft_itoa(nu);
			printf("%s\n", new);
		}
		return (0);
}

























/*
int	main(int argc, char **argv)
{

		if (argc == 2)
		{
				int	num;
				int	n;
				char	*number;

				num = atoi(argv[1]);
				n = nc(num);
				number = ft_itoa(num);
				printf("the numbers are: %i\n", n);
				printf("the string number is: %s\n", number);
		}
		return (0);
}*/
