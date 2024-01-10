/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:56:13 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 11:56:32 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>










int	ok(char c, int	b)
{
		if (c >= 'A' && c <= 'F')
				c = c + 32;
		if (c > ("0123456789abcdef")[b -1])
				return (0);
		if (c >= '0' && c <= '9')
				return (1);
		if (c >= 'a' && c <= 'f')
				return (1);
		return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
		int		i;
		int		res;
		int		sign;

		i = 0;
		res = 0;
		sign = 1;
		while (str[i] == ' ' || str[i] == '\t')
				i++;
		if (str[i] == '-')
		{
				i++;
				sign = -1;
		}
		while (str[i] && ok(str[i], str_base))
		{
				res *= str_base;
				if (str[i] >= '0' && str[i] <= '9')
						res += str[i] - '0';
				if (str[i] >= 'a' && str[i] <= 'f')
						res += str[i] - 'a' + 10;
				if (str[i] >= 'A' && str[i] <= 'F')
						res += str[i] - 'A' + 10;
				i++;
		}
		return (res * sign);		
}

























/*
int		ok(char c, int b)
{
		if (c >= 'A' && c <= 'F')
				c += 32;
		if (c > ("0123456789abcdef")[b -1])
						return (0);
		if (c >= '0' && c <= '9')
				return (1);
		if (c >= 'a' && c <= 'f')
				return (1);
		if (c >= 'A' && c <= 'F')
				return (1);
		return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
		int		res;
		int		sign;
		int		i;

		i = 0;
		sign = 1;
		res = 0;
		if (str[i] == '-')
		{
				sign = -1;
				i++;
		}
		while (str[i] && ok(str[i], str_base))
		{
				res *= str_base;
				if (str[i] >= '0' && str[i] <= '9')
						res += str[i] - '0';
				if (str[i] >= 'a' && str[i] <= 'f')
						res += str[i] - 'a' + 10;
				if (str[i] >= 'A' && str[i] <= 'F')
						res += str[i] - 'A' + 10;
				i++;
		}
		return (res * sign);
}

*/











































/*
int	ok(char c, int	b)
{
		if (c > ("0123456789abcdef"[b -1]))
				return (0);
		if (c >= '0' && c <= '9')
				return (1);
		if (c >= 'a' && c <= 'f')
				return (1);
		if (c >= 'F' && c <= 'F')
				return (1);
		return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
		int		res;
		int		sign;
		int		i;

		i = 0;
		res = 0;
		sign = 1;
		if (str[i] == '-')
		{
				sign = -1;
				i++;
		}
		while (str[i] && ok(str[i], str_base))
		{
				res *= str_base;
				if (str[i] >= '0' && str[i] <= '9')
						res += str[i] - '0';
				if (str[i] >= 'a' && str[i] <= 'f')
						res += str[i] - 'a' + 10;
				if (str[i] >= 'F' && str[i] <= 'F')
						res += str[i] - 'A' + 10;
				i++;
		}
		return (res * sign);
}

*/
































/*
int	ok(char c, int	b)
{
		(void)b;
		if (c > ("0123456789abcdef"[b - 1]))
				return (0);
//		if	(b == 2 && c > '1') two dif alternatives..
//				return (0);
//		if	((c - '0') > b) <- this doesi'nt  consider hexa limits
//			return (0);
		if	(c >= '0' && c <= '9')
				return (1);
		if	(c >= 'a' && c <= 'f')
				return (1);
		if	(c >= 'A' && c <= 'F')
				return (1);
		return (0);		
}

int	ft_atoi_base(const char *str, int str_base)
{
		int		i;
		int		sign;
		int		res;

		i = 0;
		sign = 1;
		res = 0;
		if (str[i] == '-')
		{
				sign = -1;
				i++;
		}
		while (str[i] && ok(str[i], str_base) == 1)
		{
				res *= str_base;
				if	(str[i] >= '0' && str[i] <= '9')
						res += str[i] - '0';
				if	(str[i] >= 'a' && str[i] <= 'f')
						res += str[i] - 'a' + 10;
				if	(str[i] >= 'F' && str[i] <= 'F')
						res += str[i] - 'A' + 10;
				i++;
		}
		return (res * sign);
}
*/
int		main(int argc, char **argv)
{
		if (argc >= 3)
		{
				printf("%i", ft_atoi_base(argv[1], atoi(argv[2])));
				printf("%i", atoi(argv[1]));
		}
		else 
				printf("please enter the number and its base...");
		printf("\n");
		return (0);
} 
