/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:36:15 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:35:05 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*s;
	char	*dup;
	char	*d;
	int		i;

	s = "somwher1e over the rainbow ";
	dup = strdup(s);
	d = ft_strdup(s);
	i = 0;
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
