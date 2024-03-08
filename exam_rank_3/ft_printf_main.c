/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:57:05 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/06 17:08:44 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *str, ... );

int	main(void)
{
	int		a;
	int		b;
	int c = -7514;
	a =	ft_printf("%s\n", "toto");
	a = ft_printf("Magic %s is %d\n", "number", 42);
 	a = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("\n");
	b =	printf("%s\n", "toto");
	b = printf("Magic %s is %d\n", "number", 42);
 	b = printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("%d\n", a);
	printf("%d\n", b);
	ft_printf("%d\n", c);
	return (0);
}
