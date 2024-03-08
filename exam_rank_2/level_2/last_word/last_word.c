/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:24 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:21:31 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ok(char c)
{
	if (c != ' ' && c != '\t' && c != '\0')
		return (1);
	return (0);
}

void	last_word(char *s)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s[i])
	{
		if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i - 1])))
			start = i;
		i++;
	}
	while (s[start] && ok(s[start]))
		ft_putchar(s[start++]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	ft_putchar('\n');
}
