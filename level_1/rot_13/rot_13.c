/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:57:53 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 11:03:50 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'm')
			bo(str[i] + 13);
		else if (str[i] >= 'n' && str[i] <= 'z')
			bo(str[i] - 13);
		else if (str[i] >= 'A' && str[i] <= 'M')
			bo(str[i] + 13);
		else if (str[i] >= 'N' && str[i] <= 'Z')
			bo(str[i] - 13);
		else
			bo(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	bo('\n');
	return (0);
}
