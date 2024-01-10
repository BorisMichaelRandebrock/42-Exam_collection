/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:04:10 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/30 19:40:19 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	nc(int num)
{
		int		c;

		c = 0;
		if (num == -2147483648)
				return (11);
		if (num < 0)
		{
				c++;
				num *= -1;
		}
		while (num > 0)
		{
				num /= 10;
				c++;
		}
		return (c);
}

char	*ft_itoa(int nbr)
{
		char	*res;
		int		len;

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
}

