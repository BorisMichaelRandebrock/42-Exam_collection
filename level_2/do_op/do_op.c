/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:33 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/19 16:08:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{

		if (argc == 4)
		{
				int		a;
				int		b;
				char	op;

				a = atoi(argv[1]);
				op = argv[2][0];
				b = atoi(argv[3]);
				if (op == '+')
						printf("%d", a +  b);
				if (op == '-')
						printf("%d", a -  b);
				if (op == '/')
						printf("%d", a /  b);
				if (op == '%')
						printf("%d", a %  b);
				if (op == '*')
						printf("%d", a *  b);
		}
		else
				printf("\n");
		return (0);
}
