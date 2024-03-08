/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:54:38 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 18:18:19 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

int	fatoi(char *n)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (n[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (n[i] && (n[i] >= '0' && n[i] <= '9'))
	{
		res = (res * 10) + n[i++] - '0';
	}
	return (res * sign);
}

void	boo(int n)
{
	char	numbers[10] = "0123456789";

	if (n > 9)
		boo(n / 10);
	write(1, &numbers[n % 10], 1);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (1);
		i++;
	}
	return (0);
}

void	add_prime_sum(int n)
{
	int	i;
	int	aux;
	int	res;

	i = 2;
	aux = n;
	res = 0;
	if (n == 1)
	{
		boo(0);
		return ;
	}
	while (i <= n)
	{
		if (is_prime(i) == 0)
			res += i;
		i++;
	}
	boo(res);
}

int	main(int argc, char **argv)
{
	int	res;

	if (argc != 2)
	{
		boo(0);
		bo('\n');
		return (1);
	}
	res = fatoi(argv[1]);
	if (res < 0)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (argc == 2)
		add_prime_sum(res);
	write(1, "\n", 1);
	return (0);
}
