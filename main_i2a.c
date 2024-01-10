/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_i2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:04:58 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 19:53:47 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa(int nbr);
int	nc(int num);
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
		char	*r;
		int		res = atoi(argv[1]) ;
		if (argc == 2)
		{
				r = ft_itoa(res);
				printf("%s\n", r);
		}
		return (0);
}
