/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:54:41 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 18:42:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		max(int* tab, unsigned int len);
void	print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);
unsigned char	swap_bits(unsigned char octet);

int		main(int argc, char **argv)
{
		(void) argv;
		char	oc = 'h';
		char	rev = reverse_bits(oc);
		char	sw = swap_bits(oc);
		//	int		numbs[] = {1, 5, 6, 12};
	//	int		res;
		if (argc == 2)
		{
				print_bits(oc);
				write(1, "\n", 1);
				print_bits(rev);
				write(1, "\n", 1);
				print_bits(sw);
	//			res = max(numbs, 4);
	//			printf("max number: %i\n",  res);
		}
		return (0);
}
