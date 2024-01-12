/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:21:33 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 14:30:06 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nc(int nbr)
{
	int	c;

	c = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		c++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		c++;
		nbr /= 10;
	}
	return (c);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		len;

	len = nc(nbr);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		res = NULL;
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
	res[len] = nbr + '0';
	return (res);
}

/*

int	nc(int nbr)
{
		int	c;

		c = 0;
		if (nbr == -2147483648)
				return (11);
		if (nbr < 0)
		{
				c++;
				nbr *= -1;
		}
		while (nbr > 0)
		{
				nbr /= 10;
				c++;
		}
		return (c);
}
char	*ft_itoa(int nbr)
{
		char	*res;
		int			len;

		len = nc(nbr);
		res = malloc(sizeof(char) * (len + 1));
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
		while (nbr > 0)
		{
				res[len] = (nbr % 10) + '0';
				nbr /= 10;
				len--;
		}
		return (res);
}*/
