/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:56:44 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/11 17:18:05 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	bo(char c)
{
	write(1, &c, 1);
}

void	boo(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		bo(s[i++]);
}

int	check(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	res[255];

	i = 0;
	j = 0;
	k = 0;
	res[0] = '\0';
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	j = 0;
	while (s1[j])
	{
		if (check(res, s1[j]) == 0)
		{
			res[k] = s1[j];
			k++;
			res[k] = '\0';
		}
		j++;
	}
	boo(res);
}

int	main(int argc, char **argv)
{
	char	str[256];

	str[0] = '\0';
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	bo('\n');
}
