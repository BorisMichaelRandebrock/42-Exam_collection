/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:43:38 by brandebr          #+#    #+#             */
/*   Updated: 2024/02/26 11:19:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *str, ... );

int	main(void)
{
	int 	ftprintf;
	int		_printf;
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ftprintf = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("---\n");
 	printf("%s\n", "toto");
	printf("Magic %s is %d\n ", "number", 42);
	_printf = printf("Hexadecimal for %d is %x\n", 42, 42);

	printf("%d\n", ftprintf);
	printf("%d\n", _printf);
	return (0);
}
