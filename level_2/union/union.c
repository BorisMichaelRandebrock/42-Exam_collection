/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:56:44 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/21 11:04:03 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	bo(char c)
{
		write(1, &c, 1);
}

void	boo(char *s)
{
		int		i;

		i = 0;
		while (s[i])
				bo(s[i++]);
}

int		check(char *s, char c)
{
		int		i;

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



/*
int		check(char *s, char c)
{
		int		i;

		i = 0;
		while(s[i])
		{
				if (c == s[i])
						return (1);
				i++;
		}
		return (0);
}

void	ft_union(char *s1, char *s2, char *s)
{
		char	new[255];
		int		i = 0;
		int		j = 0;

		s[0] = '\0';
		new[0] = '\0';
		while (s1[i])
		{
				s[i] = s1[i];
				i++;
		}
		while (s2[j])
		{
				s[i] = s2[j];
				i++;
				j++;
		}
		s[i] = '\0';
		i = 0;
		j = 0;
		while (s[i])
		{
				if (check(new, s[i]) == 0)
				{
						new[j] = s[i];
						j++;
						new[j] = '\0';
				}
				i++;
		}
	boo(new);
}
*/
int		main(int argc, char **argv)
{
		char	str[256];

		str[0] = '\0';
		if (argc == 3)
		{
				//ft_union(argv[1], argv[2], str);
				ft_union(argv[1], argv[2]);
			//	boo(s);
		}
		bo('\n');
}

