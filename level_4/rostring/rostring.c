/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:40:30 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 17:59:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // For write

void	pu(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

void	print_word(char *str, int i)
{
	while (str[i] != '\0' && !is_space(str[i]))
	{
		pu(str[i]);
		i++;
	}
}

void	rostring(char *str)
{
	int	i;
	int	begin_space;

	begin_space = 0;
	while (str[begin_space] != '\0' && is_space(str[begin_space]))
		begin_space++;
	i = begin_space;
	while (str[i] != '\0' && !is_space(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && !is_space(str[i]) && is_space(str[i - 1]))
		{
			while (str[i] != '\0' && !is_space(str[i]))
			{
				pu(str[i]);
				i++;
			}
			pu(' ');
		}
		i++;
	}
	print_word(str, begin_space);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	pu('\n');
	return (0);
}
