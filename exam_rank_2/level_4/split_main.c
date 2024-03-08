/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:28:43 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 15:07:37 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char *str);
int		wc(char *str);

int	main(int argc, char **argv)
{
	int		i;
	char	**res;
	int		words_count;

	i = 0;
	if (argc == 2)
	{
		res = ft_split(argv[1]);
		words_count = wc(argv[1]);
		printf("number of words found in string argv: %d\n", words_count);
		while (i < words_count)
		{
			printf("%s\n", res[i++]);
		}
		i = 0;
		while (i < words_count)
		{
			printf("%s", res[i++]);
			if (i < words_count)
				printf(" ");
		}
	}
	return (0);
}
