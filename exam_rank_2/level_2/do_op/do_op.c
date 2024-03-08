/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:33 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 13:48:42 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	if (argc == 4)
	{
		a = atoi(argv[1]);
		op = argv[2][0];
		b = atoi(argv[3]);
		if (op == '+')
			printf("%d", a + b);
		if (op == '-')
			printf("%d", a - b);
		if (op == '/')
			printf("%d", a / b);
		if (op == '%')
			printf("%d", a % b);
		if (op == '*')
			printf("%d", a * b);
	}
	else
		printf("\n");
	return (0);
}
