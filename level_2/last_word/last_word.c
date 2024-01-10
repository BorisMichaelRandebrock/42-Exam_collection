/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:24 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 17:47:16 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bu(char	c)
{
		write(1, &c, 1);
}

int		ok(char c)
{
		if (c != ' ' && c != 't' && c != '\0')
				return (1);
		return (0);
}

void	last_word(char *s)
{
		int		i;
		int		start;

		i = 0;
		start = 0;
		while (s[i])
		{
				if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i - 1])))
						start = i;
				i++;
		}
		while (ok(s[start]))
				bu(s[start++]);
}

int		main(int argc, char **argv)
{
		if (argc == 2)
				last_word(argv[1]);
		bu('\n');
}
