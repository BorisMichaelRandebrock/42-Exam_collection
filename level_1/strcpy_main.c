/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:10:33 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:34:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

int	main(int argc, char **argv)
{
	char	*str;
	char	new[100];
	char	orig[100];

	str = argv[1];
	ft_strcpy(new, str);
	ft_strcpy(orig, str);
	if (argc == 2)
	{
		printf("%s\n", new);
		printf("%s\n", orig);
	}
	return (0);
}
