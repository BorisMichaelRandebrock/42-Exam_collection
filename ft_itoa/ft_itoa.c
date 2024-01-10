/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:35:51 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/21 12:41:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		len(int n)
{
		int	c;

		c = 0;
		if (n == -2147483648)
				return (11);
		if (n < 0)
		{
				c++;
				n *= -1;
		}
		while (n > 0)
		{
				n /=  10;
				c++;
		}
		return (c);
}

char	*ft_itoa(int nbr)
{
		int		length = len(nbr);
		char	*res;

		res = malloc(sizeof(char) * (length + 1));
		if (!res)
				free(res);
		if (nbr == -2147483648)
		{
				res = "-2147483648";
				return (res);
		}
		if (nbr < 0)
		{
				res[0] = '-';
				nbr *= -1;
		}
		res[length] = '\0';
		length--;
		while (nbr > 9)
		{
				res[length] = (nbr % 10) + '0';
				nbr /= 10;
				length--;
		}
		res[length] = (nbr % 10) + '0';
		return (res);
}

int		main(int argc, char **argv)
{
		int 	num = atoi(argv[1]);
//		int		i = 0;
		char	*res = NULL;
		
		if (argc == 2)
		{
				res = ft_itoa(num);
				printf("%s\n", res);
		}
		return (0);
}

/*
int		count(int n)
{
		int		c;

		c = 0;
		if (n == -2147483648)
				return (11);
		if (n < 0)
		{
				c++;
				n *= -1;
		}
		while (n > 0)
		{
				c++;
				n /= 10;
		}
		return (c);
}

char    *ft_itoa(int nbr)
{
		char	*res;
		int		len;
	//	int		i;

		len = count(nbr);
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
				free(res);
		res[len] = '\0';
		len--;
		if (nbr == -2147483648)
		{
				res = "-2147483648";
				return (res);
		}
		if (nbr < 0)
		{
				res[0] = '-';
				nbr *= -1;
		}
		while (nbr > 9)
		{
				res[len] = (nbr % 10) + '0';
				nbr /= 10;
				len--;
		}
		res[len] = (nbr % 10) + '0';
		return (res);
}

int		main(int argc, char **argv)
{
		int		n;
		int		nc;
		char	*res;

		n = 0;
		res = NULL;
		if (argc == 2)
		{
				n = atoi(argv[1]);
				nc = count(n);
//				printf("amount of numbers: %i", nc);
				res = ft_itoa(n);
				printf("%s", res);
		}
		return (0);
}
*/





















/*
int		nc(int n)
{
		int		i;

		i = 0;
		if (n == -2147483648)
				return (11);
		if (n < 0)
		{
				n *= -1;
				i++;
		}
		while (n > 0)
		{
				n /= 10;
				i++;
		}
//		printf("number of numbers: \n %i", i);
		return (i);
}

char    *ft_itoa(int nbr)
{
		char	*res;
		int		len;

		res = NULL;
		len = nc(nbr);
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
				free(res);
		res[len] = '\0';
		len--;
		if (nbr == -2147483648)
				return ("-2147483648");
		if (nbr < 0)
		{
				res[0] = '-';
				nbr *= -1;
		}
		while (nbr > 9)
		{
				res[len] = (nbr % 10) + '0';
				nbr /= 10;
				len--;
		}
		res[len] = (nbr % 10) + '0';
		return (res);
}

int	main(int argc, char **argv)
{
		int		num;
		if (argc == 2)
		{
				num = atoi(argv[1]);
			printf("%s",ft_itoa(num));
		}
		return (0);
}
*/
































/*
int		lc(int nbr)
{
		int len;

		len = 0;
		if (nbr == -2147483648)
				return (11);
		if (nbr < 0)
		{
				len++;
				nbr *= -1;
		}
		while (nbr > 0)
		{
				nbr /= 10;
				len++;
		}
		return (len);
}

char	*ft_itoa(int nbr)
{
		int		len;
		char	*res;

		len = lc(nbr);
		res = malloc(sizeof(char) * (len + 1));
		{
				if (!res)
						free(res);
		}
		res[len] = '\0';
		len--;
		if (nbr == -2147483648)
				return ("-2147483648");
		if (nbr < 0)
		{
				nbr *= -1;
				res[0] = '-';
		}
		while (nbr > 9)
		{
				res[len] = (nbr % 10) + '0';
				nbr /= 10;
				len--;
		}
		res[len] = (nbr % 10) + '0';
		return (res);
}

int 	main(int argc, char **argv)
{
		int nbr;

		nbr = atoi(argv[1]);
//		printf("%i",lc(nbr));
		if (argc == 2)
				printf("%s",ft_itoa(nbr));
		(void)argc;
		(void)argv;
		return (0);
}
*/























/*
int		count(int nbr)
{
		int		i;

		i = 0;
		if (nbr == -2147483648)
				return (10);
		if (nbr < 0)
				nbr *= -1;
		while (nbr > 0)
		{
				nbr /= 10;
				i++;
		}
		return (i);
}

char	*ft_itoa(int nbr)
{
		int		len;
		char	*res;

		res = NULL;
		len = count(nbr);
		if (nbr < 0)
		{
				len++;
				nbr *= -1;
				res = malloc((len + 1) * sizeof(char));
				res[0] = '-';
		}
		else
				res = malloc((len + 1) * sizeof(char));
		res[len] = '\0';
		len--;
		if (nbr == -2147483648)
		{
				res = "-2147483648";
				return (res);
		}
		while (nbr > 9)
		{
				res[len] = (nbr % 10) + '0';
				nbr = nbr / 10;
				len--;
		}
		res[len] = (nbr % 10) + '0';
	//	printf("nlength: %i", len); 
		return (res);
}

int		main(int argc, char **argv)
{
		int		i;
		int	nbr;

		i = 0;
		nbr = atoi(argv[1]);
		if (argc == 2)
				printf("%s", ft_itoa(nbr));
		else
				printf("please be so kind to enter a number");
		printf("\n");
		return (0);
}


*/
































/*
int		leng(int n)
{
		int		i;

		i = 0;
		if (n == -2147483648)
				return (10);
		else if (n < 0)
				n *= -1;
		while (n > 0)
		{
			n = n / 10;
				i++;
		}
		return (i);
}

char	*ft_itoa(int nbr)
{
		char	*res;
		int		len;

		res = NULL;
		len = leng(nbr);
		if (nbr < 0)
		{
				len++;
				res = malloc((len + 1) * sizeof(char)); 
				nbr *= -1;
				res[0] = '-';
		}
		else
				res = malloc((len + 1) * sizeof(char)); 
		if (!res)
				free(res);
		res[len] = '\0';
		len--;
		while (nbr > 9)
		{
				res[len] = (nbr % 10) + '0';
				nbr /= 10;
				len--;
		}
		res[len] = nbr % 10 + '0';
		return (res);
}

int	main(int argc, char **argv)
{
		int	puta;

		if (argc < 2)
		{
				printf("please be so kind to enter a number... sometthing like 42 ... or so.. 🤏");
				return (1);
		}

		puta = atoi(argv[1]);
		printf("💩 %s",ft_itoa(puta));
		printf("\n");
		return (0);
}
*/
