/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpbrk_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:58:21 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:35:10 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("the pointer retur by ft: %p\n", ft_strpbrk(argv[1], argv[2]));
		printf("the pointer retur by or: %p\n", strpbrk(argv[1], argv[2]));
		printf("the pointer retur by ft: %c\n", *ft_strpbrk(argv[1], argv[2]));
		printf("the pointer retur by or: %c\n", *strpbrk(argv[1], argv[2]));
	}
	return (0);
}
// ./a.out "por la presente ha sido " "ent"
