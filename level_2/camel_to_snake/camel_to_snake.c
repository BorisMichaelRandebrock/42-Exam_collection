/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:14:41 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/19 15:48:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pu(char c)
{
		write(1, &c, 1);
}

void	camel_to_snake(char *s)
{
		int		i;

		i = 0;
		while (s[i])
		{
				if (s[i] >= 'A' && s[i] <= 'Z')
				{	
						pu('_');
						pu(s[i] + 32);
				}
				else
						pu(s[i]);
				i++;
		}
}

int		main(int argc, char **argv)
{
		if (argc  == 2)
				camel_to_snake(argv[1]);
		pu('\n');
		return (0);
}
