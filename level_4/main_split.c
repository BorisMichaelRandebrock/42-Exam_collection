/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:28:43 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 17:50:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    **ft_split(char *str);
int	wc(char *str);

int	main(int argc, char **argv)
{
		int 	i = 0;
		if (argc == 2)
		{
				char	**res = ft_split(argv[1]);
				int	words_count = wc(argv[1]);
				printf("number of words found in string argv: %d\n", words_count);
				while (i < words_count)
				{
						printf("%s\n",res[i++]);
				}
				i = 0;
				while (i < words_count)
				{
						printf("%s",res[i++]);
						if (i < words_count )
								printf(" ");
				}
		
		}
		return (0);
}




































/*
int	main(int argc, char **argv)
{
		int	words;
		int i = 0;

		if (argc == 2)
		{
				char	**res;
				res = ft_split(argv[1]);
				words = wc(argv[1]);
				printf("number of words are: %d\n", words);
				while (res[i])
						printf("%s\n", res[i++]);
		}
		return (0);
}*/
