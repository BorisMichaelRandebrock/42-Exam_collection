/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:09:44 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 10:11:58 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_number(int n)
{
	char	numbers[10] = "0123456789";

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		put_number(n / 10);
	write(1, &numbers[n % 10], 1);
}

void	fizzbuzz(int n)
{
	if (n % 15 == 0)
		write(1, "fizzbuzz", 8);
	else if (n % 3 == 0)
		write(1, "fizz", 4);
	else if (n % 5 == 0)
		write(1, "buzz", 4);
	else
		put_number(n);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		fizzbuzz(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
