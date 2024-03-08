/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backwards_rev_wstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:43:38 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 17:55:02 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ok(char c)
{
	if (c != ' ' && c != '\t' && c != '\0' /*c > 32 && c < 127*/)
		return (1);
	return (0);
}

int	ft_check(int start, char *str)
{
	while (start >= 0)
	{
		if (ok(str[start]))
			return (1);
		start--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	i;
	int	flag;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		while (i >= 0)
		{
			while (argv[1][i] == '\0' || !ok(argv[1][i]))
				i--;
			end = i;
			while (i >= 0 && argv[1][i] && ok(argv[1][i]))
				i--;
			start = i + 1;
			flag = ft_check(start - 1, argv[1]);
			while (start <= end)
			{
				write(1, &argv[1][start], 1);
				start++;
			}
			if (flag > 0)
			{
				write(1, " ", 1);
				flag = 0;
			}
			i--;
		}
	}
	write(1, "\n", 1);
}
