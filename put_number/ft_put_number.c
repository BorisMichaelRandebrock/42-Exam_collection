/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:40:55 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/15 19:07:28 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

 void    ft_putnbr(int n)
{
		char	*num = "0123456789";
		
		if (n < 0)
		{
				write(1, "-", 1);
			 n *= -1;
		}

		if (n > 9)
				ft_putnbr(n / 10);
		write(1, &num[n % 10], 1);
}

void	hex(int n/*, int basei*/)
{
		char	num[] = "0123456789abcdef";
		
		if (n > 15)
				hex(n / 16);
		write(1, &num[n % 16], 1);
}











































/*
 void    ft_putnbr(int n)
{
		char	*num = "0123456789";

		if (n > 9)
				ft_putnbr(n / 10);
		write(1, &num[n % 10], 1);
}

void	hex(int n, int base)
{
		char	*num = "0123456789abcdef";

		if (n > base - 1)
				(hex(n / base, base));
		write(1, &num[n % base], 1);
}
*/
int		ok(char c, int b)
{
		if (b == 2 && c > '1')
				return (0);
		if (b == 4  && c > '3')
				return (0);
		if (b == 8 && c > '7')
				return (0);
		if (b == 10 && c > '9')
				return (0);
		if (c >= '0' && c <= '9')
				return (1);
		if (c >= 'a' && c <= 'f')
				return (1);
		if (c >= 'A' && c <= 'F')
				return (1);
		return (0);
}

int		batoi(const char *str, int str_base)
{
		int		i;
		int		sign;
		int		res;

		i = 0;
		sign = 1;
		res = 0;
		if (str[i] < '-')
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























/*
void	ft_putnbr(int n)
{
		char ns[] = "0123456789";

		if (n > 9)
				ft_putnbr(n / 10);
		write(1, &ns[n % 10], 1);
}

void	hex(int n, int base)
{
		char	*hexs = "0123456789abcdef";

		if (n > base)
				hex((n / base), base);
		write(1, &hexs[n % base], 1);
}
*
int		ok(char c, int b)
{
		if (b == 8 && c > '7')
				return (0);
		if (b == 4 && c > '3')
				return (0);
		if (b == 2 && c > '1')
				return (0);
		if (c >= '0' && c <= '9')
				return (1);
		if (c >= 'a' && c <= 'f')
				return (1);
		if (c >= 'F' && c <= 'F')
				return (1);
		return (0);
}

int		batoi(const char *str, int str_base)
{
		int		i;
		int		res;
		int		sign;

		i = 0;
		res = 0;
		sign = 1;
		while (str[i] && ok(str[i], str_base) == 1)
		{
				res *= str_base;
				if (str[i] >= '0' && str[i] <= '9')
						res += str[i] - '0';
				if (str[i] >= 'A' && str[i] <= 'F')
						res += str[i] - 'A' + 10;
				if (str[i] >= 'a' && str[i] <= 'f')
						res += str[i] - 'a' + 10;
				i++;
		}
		return (res * sign);
}
*/




















/*
void	ft_putnbr(int n)
{
	//	char	numbers[10] = "0123456789";
		char	*numbers;// = "0123456789";

		numbers = "0123456789";
		if (n < 0)
		{
				write(1, "-", 1);
				n *= -1;
		}
		if (n > 9)
				ft_putnbr(n / 10);
		write(1, &numbers[n % 10], 1);
}
*/
int	main(int argc, char **argv)
{
		char		*bo;
		int		some;
		int		base;

		bo = argv[1];
		some = atoi(argv[1]);
		if (argc == 2)
				ft_putnbr(some);
		 if (argc == 3)
		{
				base = atoi(argv[2]);
				base = batoi(bo , base);
				hex(base);
				printf("%i", base);
			//	hex(bo, base);
		}
				write(1, "\n",1);
		int decimalNumber = 43981; // 0xABCD in hexadecimal

		write(1, "Decimal: ", 9);
    	ft_putnbr(decimalNumber);
    	write(1, "\nHexadecimal: ", 14);
   		hex(decimalNumber);
    	write(1, "\n", 1);

		return (0);
}
