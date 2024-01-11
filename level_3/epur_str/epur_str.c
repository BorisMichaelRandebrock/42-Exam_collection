/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:21:13 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 18:30:52 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	epur_str(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		while (str[i])
		{
			if (is_space(str[i]))
				space = 1;
			if (!is_space(str[i]))
			{
				if (space)
					write(1, " ", 1);
				write(1, &str[i], 1);
				space = 0;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
