/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:13:28 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 11:25:48 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char *search, char *replace)
{
	int	i;

	i = 0;
	(void)search;
	(void)replace;
	while (str[i])
	{
		if (str[i] == search[0])
			bo(replace[0]);
		else
			bo(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4 && !((argv[2][1]) && (argv[3][1])))
		search_and_replace(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
	return (0);
}
