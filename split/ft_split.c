/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:52:36 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/21 12:19:53 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	bo(char c)
{
		write(1, &c, 1);
}

void	boo(char *s)
{
		int		i;

		i = 0;
		while (s[i])
		{
				bo(s[i]);
				i++;
		}
}

int		ok(char c)
{
		if (c != ' ' && c != '\t' && c != '\0')
				return (1);
		return (0);
}

int		wc(char *str)
{
		int		i;
		int		ws;

		i = 0; 
		ws = 0;
		while (str[i])
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
						ws++;
				i++;
		}
		return (ws);
}

char	**ft_split(char *str)
{
		char	**res;
		int		words;
		int		w;
		int		i;
		int		j;
		int		start;
		int		end;

		words = wc(str);
		res = (char **)malloc(sizeof(char *) * (words + 1));
		if (!res)
				res = NULL;
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
						res[w] = malloc(sizeof(char) * ((end - start) +  1));
						if (!res[w])
								free(res);
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

int		main(int argc, char **argv)
{
		char	**res;
		int		i;

		i = 0;
		res = NULL;
		if (argc == 2)
		{
				res = ft_split(argv[1]);
				while (res[i])
				{
					boo(res[i]);
					bo('\n');
					i++;
				}
		}
		bo('\n');
		return (0);
}



/*

void	puc(char c)
{
		write(1, &c, 1);
}

int		ok(char c)
{
		if (c != ' ' && c != '\t')
				return (1);
		return (0);
}

int		wc(char *s)
{
		int		i;
		int		w;

		i = 0;
		w = 0;
		while (s[i])
		{
				if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i - 1])))
						w++;
				i++;
		}
		return (w);
}

char    **ft_split(char *str)
{
		char	**res;
		int		words;
		int		w;
		int		i;
		int		j;
		int		start;
		int		end;

		words = wc(str);
		res = (char **)malloc(sizeof(char *) * (words + 1));
		w = 0;
		i = 0;
		if (!res)
				res = NULL;
		while (w < words)
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
				{
						j = 0;
						start = i;
						end = start;
						while (str[end] && ok(str[end]))
								end++;
						res[w] = (char *)malloc(sizeof(char) * ((end - start) + 1));
						if (!res[w])
								free(res[w]);
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
		return (res);
}

int		main(int argc, char **argv)
{
		char	**res;
		int		i;

		i = 0;
		if (argc == 2)
		{
				res = ft_split(argv[1]);
				while (res[i])
						printf("%s\n", res[i++]);
//				printf("number of words: %i\n", wc(argv[1]));
		}
		return (0);
}


*/









/*
int		ok(char c)
{
		if (c != ' ' && c != '\t' && c != '\0')
				return (1);
		return (0);
}

int		wc(char *s)
{
		int		i;
		int		c;

		i = 0;
		c = 0;
		while (s[i])
		{
				if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i - 1])))
						c++;
				i++;
		}
		return (c);
}


char    **ft_split(char *str)
{
		char	**res;
		int		words;
		int		w;
		int		i;
		int		j;
		int		start;
		int		end;

		words =  wc(str);
		res = (char **)malloc(sizeof(char *) * (words + 1));
		i = 0;
		w = 0;
		while (w < words)
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
				{
						j = 0;
						start = i;
						end = start;
						while (ok(str[end]))
								end++;
						res[w] = (char *)malloc(sizeof(char) * ((end - start) + 1));
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

int		main(int argc, char **argv)
{
		char	**res;
		int		i;

		i = 0;
		res = NULL;
		if (argc == 2)
		{
//				printf("number of words: %i",wc(argv[1]));
				res = ft_split(argv[1]);
						printf("%s\n", res[i]);
				while (res[i])
				{
						printf("%s\n", res[i]);
						i++;
				}
		}
		return (0);			
}

*/












































/*
int		ok(char c)
{
		if (c > ' ' && c <= '~')
				return (1);
		return (0);
}

int		wc(char *s)
{
		int		i;
		int		words;

		i = 0;
		words = 0;
		while (s[i])
		{
				if ((i == 0 && ok(s[i])) || (!ok(s[i]) && ok(s[i + 1])))
						words++;
				i++;
		}
		return (words);
}

char    **ft_split(char *str)
{
		char	**res;
		int		len;
		int		word;
		int		i;
		int		j;
		int		start;
		int		end;
		
		word = 0;
		i = 0;=
		len = wc(str);
		res = malloc(sizeof(char *) * (len + 1));
		if (!res)
				free(res);
		while (word < len)
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i -1])))
				{			
						start = i;
						j = 0;
						while (ok(str[i]))
								end = i++;
						res[word] = malloc(sizeof(char) * ((end - start) + 1));
						if (!res[word])
								free(res[word]);
						while (start <= end)
						{
								res[word][j] = str[start];
								start++;
								j++;
						}
						res[word][j] = '\0';
						word++;
				}
				i++;
		}
		res[word] = NULL;
		return (res);
}

int	main(int argc, char **argv)
{
		int		i;
		char	**res;	
		int		wo;

		i = 0;
		wo = count(argv[1]);
		res = NULL;
		if (argc == 2)
		{
				res = ft_split(argv[1]);
				while (res[i])
				{
					printf("%s\n", res[i]);
					i++;
				}
				i = 0;
					printf("\n");
				while (i < wo)
					printf("%s\n", res[i++]);
						
		}
		return (0);
}
*/
