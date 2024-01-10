/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:43:31 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 10:57:16 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_strdup(char *src)
{
		int		i;
		char	*d;

		i = 0;
		while (src[i])
				i++;
		d = malloc(sizeof(char) * (i + 1));
		if (!d)
				free(d);
		i = 0;
		while (src[i])
		{
				d[i] = src[i];
				i++;
		}
		d[i] = '\0';
		return (d);
}

int		main(void)
{
		char	*s = "somwher1e over the rainbow ";
		char	*dup = strdup(s);
		char	*d = ft_strdup(s);

		int i = 0;
		while (dup[i])
				i++;
		printf("orig length: %i\n", i);
		i = 0;
		while (d[i])
				i++;
		printf("my  length: %i\n", i);

		printf("original function: %s\n", dup);
		printf("mine: %s\n", d);
		return (0);
}
