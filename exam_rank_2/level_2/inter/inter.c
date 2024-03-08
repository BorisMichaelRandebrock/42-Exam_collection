/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:59:25 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 14:16:01 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

int	check(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	char	new[256];
	int		i;
	int		j;

	new[0] = '\0';
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (check(new, s1[i]) == 0)
		{
			new[j] = s1[i];
			j++;
			new[j] = '\0';
		}
		i++;
	}
	i = 0;
	j = 0;
	while (new[i])
	{
		if (check(s2, new[i]) == 1)
			bo(new[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
