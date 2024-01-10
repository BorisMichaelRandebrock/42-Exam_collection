/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:12:14 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 13:26:07 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sw(char *a, char *b)
{
		char	swap;
		
		swap = *a;
		*a = *b;
		*b = swap;
}

char    *ft_strrev(char *str)
{
		int		i;
		int		len;
		char		swap;

		i = 0;
		len = 0;
		while (str[len])
				len++;
		len--;
		while (i < len)
		{
				swap = str[i];
				str[i] = str[len];
				str[len] = swap;
				i++;
				len--;
		}
		return (str);
}

int		main(int ac, char **av)
{
		if (ac == 1)
			return(printf("mascosas\n"));
		char *res;

		res = ft_strrev(av[1]);
		printf("%s",res);
}
