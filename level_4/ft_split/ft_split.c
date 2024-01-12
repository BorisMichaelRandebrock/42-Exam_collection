/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:31:57 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:57:12 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ok(char c)
{
	if (c != ' ' && c != '\t' && c != '\0')
		return (1);
	return (0);
}

int	wc(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
			c++;
		i++;
	}
	return (c);
}

char	**ft_split(char *str)
{
	char **res;
	int words;
	int w;
	int i;
	int j;
	int start;
	int end;

	words = wc(str);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	w = 0;
	i = 0;
	while (w < words)
	{
		if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
		{
			j = 0;
			start = i;
			end = start;
			while (ok(str[end]))
				end++;
			res[w] = malloc(sizeof(char) * ((end - start) + 1));
			while (start < end)
			{
				res[w][j] = str[start];
				start++;
				j++;
			}
			res[w][j] = '\0';
			w++;
		}
		i++;
	}
	res[words] = NULL;
	return (res);
}
