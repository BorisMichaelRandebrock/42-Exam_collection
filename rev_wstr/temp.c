
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int		ok(char	c)
{
		if (c > 32 && c < 127)
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
				if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i -1])))
						c++;
				i++;
		}
		return (c);
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

		i = 0;
		word = 0;
		len = wc(str);
		res = (char **)malloc(sizeof(char *) * (len + 1));
		if(!res)
				free(res);
		while (word < len)
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
				{
						start = i;
						end = i;
						j = 0;
						while (ok(str[end]))
								end++;
						res[word] = (char *)malloc(sizeof(char) * ((end -start) + 1)); 
						while (start < end)
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
		return (res);
}


int		main(int argc, char **argv)
{
		int		len;
		int		i;
		char	**res;

		i = 0;
		if (argc == 2)
		{
				len = wc(argv[1]);
				res = ft_split(argv[1]);
				while (i < len)
						printf("%s\n", res[i++]);
				printf("\n");
		}
		return (0);
}
