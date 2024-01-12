/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:27 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:35:01 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject);

int	main(int argc, char **argv)
{
	char	*s;
	char	*s1;

	s = "somwher1e over the rainbow ";
	s1 = " yx1 :wz1";
	printf("number of chars spannned: %i\n", (int)strcspn(s, s1));
	printf("number of chars spannned: %i\n", (int)ft_strcspn(s, s1));
	if (argc == 3)
	{
		printf("ft result:%zu\n", ft_strcspn(argv[1], argv[2]));
		printf("orig result:%zu\n", strcspn(argv[1], argv[2]));
	}
	return (0);
}
// ./a.out "por la presente ha sido " "ent"
