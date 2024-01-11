/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:54:41 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 16:54:58 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
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

unsigned char	reverse_bits(unsigned char octet);

int	main(int argc, char **argv)
{
	char	oc;
	char	rev;

	(void)argv;
	(void)argc;
	oc = 'h';
	rev = reverse_bits(oc);
	print_bits(oc);
	write(1, "\n", 1);
	print_bits(rev);
	return (0);
}
