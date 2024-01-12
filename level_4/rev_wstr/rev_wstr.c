/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:22:23 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 16:28:08 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ps(char c)
{
	write(1, &c, 1);
}

int	ok(char c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

void	rev_wstr(char *s)
{
	int	wc;
	int	i;
	int	len;
	int	start;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && ok(s[i])) || (!ok(s[i - 1]) && ok(s[i])))
			wc++;
		i++;
	}
	i--;
	while (s[i])
	{
		if (ok(s[i]))
		{
			len = 1;
			while (i >= 0 && ok(s[i - 1]))
			{
				len++;
				--i;
			}
			start = i;
			wc--;
			while (len--)
				ps(s[start++]);
			if (wc > 0)
				ps(' ');
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	ps('\n');
	return (0);
}
