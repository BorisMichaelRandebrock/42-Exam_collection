/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:12:32 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 11:17:28 by brandebr         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	result;

	(void)argv;
	if (argc > 1)
	{
		result = argc - 1;
		pun(result);
	}
	write(1, "\n", 1);
	return (0);
}
