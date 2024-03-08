/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:21:56 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 18:55:12 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
