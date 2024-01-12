/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:21:08 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:31:07 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		nc(int nbr);
char	*ft_itoa(int nbr);

int	main(int argc, char **argv)
{
	int		nu;
	int		ns;
	char	*new;

	if (argc == 2)
	{
		nu = atoi(argv[1]);
		ns = nc(nu);
		printf("the numbers found in the number introduced are totalling:\n%d\n",
			ns);
		new = ft_itoa(nu);
		printf("%s\n", new);
	}
	return (0);
}
