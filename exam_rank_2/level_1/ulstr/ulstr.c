/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:28:27 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 11:33:57 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

void	ulstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			bo(str[i] - 32);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			bo(str[i] + 32);
		else
			bo(str[i]);
		i++;
	}
}
int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	bo('\n');
	return (0);
}
