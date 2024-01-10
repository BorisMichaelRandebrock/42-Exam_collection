/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:52:35 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/18 11:39:38 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	pu(char c)
{
		write(1, &c, 1);
}

int		ok(char c)
{
		if (c != ' ' && c != '\t' && c != '\0')
				return (1);
		return (0);
}

void	last_word(char *str)
{
		int		i;
		int		start;
		
		i = 0;
		start = 0;
		while (str[i])
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i -1])))
						start = i;
				i++;
		}
		while (str[start] && ok(str[start]))
				pu(str[start++]);
}

void	first(char *s)
{
		int		i;

		i = 0;
		while (s[i] && !ok(s[i]))
				i++;
		while (s[i] && ok(s[i]))
				pu(s[i++]);
}

int		main(int argc, char  **argv)
{
		if (argc == 2)
		{
				last_word(argv[1]);
				pu('\n');
				first(argv[1]);
		}
		pu('\n');
		return (0);
}
























/*
static void	bo(char c)
{
		write(1, &c, 1);
}

static int		ok(char c)
{
		if (c > 32 && c < 127)
				return (1);
		return (0);
}

void	last_word(char *str)
{
		int		i;
		int		start;

		i = 0;
		start = 0;
		while (str[i])
		{
				if (!ok(str[i]) && ok(str[i + 1]))
						start = i + 1;
				i++;
		}
		while (ok(str[start]))
				bo(str[start++]);
}

int	main(int argc, char **argv)
{
		if (argc == 2)
			last_word(argv[1]);
		bo('\n');
}
*/
