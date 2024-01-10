/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:46 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 10:03:53 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
		int		i;

		i = 0;
		while (s1[i])
		{
				if (s1[i] != s2[i])
						return (s1[i] - s2[i]);
				i++;
		}
		return (s1[i] - s2[i]);
}

int		main(void)
{
		char	*s = "somwhere over the rainbow ";
		char	*s1 = "somwhere ober the rainbow";

		printf("%i", strcmp(s, s1));
		printf("%i", ft_strcmp(s, s1));
		return (0);
}
