/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:22:23 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/07 12:08:56 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

void	ps(char c)
{
		write(1, &c, 1);
}

int		ok(char c)
{
		if (c > 32 && c < 127)
				return (1);
		return (0);
}

void	rev_wstr(char *s)
{
	int	wc = 0;
	int	i = 0;
	int	len;
	int	start;

	while (s[i])
	{
			if ((i == 0 &&  ok(s[i])) || (!ok(s[i - 1]) &&  ok(s[i])))
					wc++;
			i++;
	}
	i--;
	while (s[i])
	{
		if (ok(s[i]))
		{
			len = 1;
			while (i >= 0 && ok(s[i - 1]))
			{
					len++;
					--i;
			}
			start = i;
			wc--;
			while (len--)
					ps(s[start++]);
			if (wc > 0)
					ps(' ');
		}
		i--;
	}
}


/*
static void	bo(char c)
{
		write(1, &c, 1);
}

static int		ok(char c)
{
		if (c > 32 && c <  127)
				return (1);
		return (0);
}

static int leng(char *s)
{
		int		i;

		i = 0;
		while (s[i])
				i++;
		return (i);
}

int	wc(char *s)
{
		int	ws;
		int	i;

		ws = 0;
		i = 0;
		while (s[i])
		{
				if ((i == 0 && ok(s[i])) || (ok(s[i]) && !ok(s[i -1])))
						ws++;
				i++;
		}
		return (ws);
}

int 	last(char *str, int len)
{
		int		i;
		int		start;
		int		length;


		i = 0;
		start = 0;
		length = 0;
		while (i < len)
		{
				if (ok(str[i]) && !ok(str[i - 1]))
						start = i;
				i++;
		}
		while (ok(str[start]))
		{
				bo(str[start]);
				start++;
				length++;
		}
		return (length);
}

void    rev_wstr(char *str)
{
		int		i;
		int		start;
		int		len;
		int		words;
		

		i = 0;
		len = leng(str);
		words = wc(str);
		start = 0;
		while (len >= 0)
		{
			
			if (ok(str[len]) && !ok(str[len - 1]))
			{
					start = len;
					len -= last(str, len);
					words--;
			if (start > 0)
					bo(' ');
			}
			len--;
		}
	printf("%i",wc(str));
}


void    rev_wstr(char *str)
{
		int		len;
		int		pr;
		int		space;
		int		start;

		len = leng(str) -1;
		space = 0;
		start = 0;
		while (str[start])
		{
				while  (!ok(str[start]))
						start++;
				break ;
		}
		while (len >= 0)
		{
				if (len == start)
						space = 1;
				if ((len == start) ||( !ok(str[len - 1]) && ok(str[len])))
				{
						pr = len;
						while (ok(str[pr]))
								bo(str[pr++]);
						if (space == 0)
								write(1, " ", 1);
				}
				len--;
		}
}




void	rev_wstr(char *str)
{
		int		i;
	//	int		start;
		int		next;
		int		flag;

		i = 0;
		flag = 0;
		while (str[i])
		{
	//			if (!ok(str[i]) && ok(str[i + 1]))
	//			{
	//					start = i + 1;
	//					next = i;
	//			}
	//			i++;
		}
		i--;
		next = i;
		while ( next >= 0)
		{
				while (!ok(str[next]))
				{
						next--;
						i--;
				}
				if (next == 0)
						flag = 1;
				while ((next == 0 && ok(str[next])) || (ok(str[next]) && !ok(str[next -1])))
				{
						while (ok(str[next]))
							bo(str[next++]);
						if (i > 0)
								bo(' ');
				}
				i--;
				flag = 0;
				next = i;
		}
}
*/
int		main(int argc, char **argv)
{
		if (argc == 2)
				rev_wstr(argv[1]);
		ps('\n');
		return (0);
}



