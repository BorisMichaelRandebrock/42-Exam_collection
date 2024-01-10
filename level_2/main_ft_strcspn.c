/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strcspn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:27 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/05 18:15:20 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject);

int	main(int argc, char **argv)
{
		if (argc == 3)
		{
				printf("ft result:%zu\n", ft_strcspn(argv[1], argv[2]));
				printf("orig result:%zu\n", strcspn(argv[1], argv[2]));
		}
		return (0);
}
// ./a.out "por la presente ha sido " "ent"
