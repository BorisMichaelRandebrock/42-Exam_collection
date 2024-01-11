/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:46:59 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 18:55:56 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
		{
			j++;
			i++;
		}
		else
			j++;
	}
	if (argv[1][i] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
