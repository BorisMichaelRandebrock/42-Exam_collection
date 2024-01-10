/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:42:33 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 20:05:52 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    **ft_split(char *str);
int ok(char c);
int wc(char *str);
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
		int i = 0;
	//	int		res = atoi(argv[1]) ;
		if (argc == 2)
		{
				int num;

				num = wc(argv[1]);
				char	**r;
				r = ft_split(argv[1]);
				printf("%i\n", num);
				while (r[i])
				{
						printf("%s\n", r[i]);
						i++;
				}
		}
		return (0);
}
