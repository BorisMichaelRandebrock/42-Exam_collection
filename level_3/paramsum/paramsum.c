/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:12:32 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 19:00:47 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pun(int num)
{
	char	str[] = "0123456789";

	if (num > 9)
		pun(num / 10);
	write(1, &str[num % 10], 1);
}

int	paramsum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	result;
	int	i;

	(void)argv;
	i = 0;
	result = 0;
	if (argc <= 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	result = argc - 1;
	pun(result);
	write(1, "\n", 1);
	return (0);
}
