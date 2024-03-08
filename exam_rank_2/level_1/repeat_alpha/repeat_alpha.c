/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:08:54 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 10:42:29 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

void	pu_char_a(char c, int i)
{
	i--;
	while (i > 0)
	{
		bo(c);
		i--;
	}
}

int	ok(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	repeat_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ok(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				pu_char_a(str[i], (str[i] + 1) - 'a');
			else if (str[i] >= 'A' && str[i] <= 'Z')
				pu_char_a(str[i], (str[i] + 1) - 'A');
		}
		bo(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	bo('\n');
	return (0);
}
