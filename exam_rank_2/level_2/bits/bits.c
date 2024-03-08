/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:32:19 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/30 17:21:15 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_bit(unsigned char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	return (((octet >> 0) & 1) << 7) |\
		(((octet >> 1) & 1) << 6) |\
		(((octet >> 2) & 1) << 5) |\
		(((octet >> 3) & 1) << 4) |\
		(((octet >> 4) & 1) << 3) |\
		(((octet >> 5) & 1) << 2) |\
		(((octet >> 6) & 1) << 1) |\
		(((octet >> 7) & 1) << 0);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}

int	main(int argc, char **argv)
{
	unsigned char	octet;
	unsigned char	reversed;
	unsigned char	swapped;
	int				pot;

	octet = 'h';
	reversed = reverse_bits(octet);
	if (argc == 1)
	{
		write(1, "please enter a number", 21);
		return (0);
	}
	pot = atoi(argv[1]);
	swapped = swap_bits(octet); // Should result in 0110 0100
	print_bit(octet);
	write(1, "\n", 1);
	print_bit(reversed);
	write(1, "\n", 1);
	print_bit(swapped);
	write(1, "\n", 1);
	print_bit(octet);
	write(1, "\n", 1);
	printf("0: %d\n", is_power_of_2(0));
	printf("2 %d\n", is_power_of_2(2));
	printf("4  %d\n", is_power_of_2(4));
	printf("6 %d\n", is_power_of_2(6));
	printf("8 %d\n", is_power_of_2(8));
	printf("32 %d\n", is_power_of_2(32));
	printf("42 %d\n", is_power_of_2(42));
	printf("67 %d\n", is_power_of_2(67));
	printf("124 %d\n", is_power_of_2(124));
	printf("256 %d\n", is_power_of_2(256));
	if (is_power_of_2(pot) == 1)
		printf("%d is a power of 2\n", pot);
	else
		printf("%d is not a power of 2\n", pot);
	return (0);
}
