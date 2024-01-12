/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:53:45 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:35:14 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrev(char *str);

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s", ft_strrev(argv[1]));
	return (0);
}
