/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:05:06 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/20 10:40:54 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <string.h>
  #include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
		size_t		i;
		size_t		j;

		i = 0;
		while (s[i])
		{
				j = 0;
				while (reject[j])
				{
						if (reject[j] == s[i])
								return (i);
						j++;
				}
				i++;
		}
		return (i);
}

int		main(void)
{
		char	*s = "somwher1e over the rainbow ";
		char	*s1 = " yx1 :wz1";

		printf("number of chars spannned: %i\n", (int)strcspn(s, s1));
		printf("number of chars spannned: %i\n", (int)ft_strcspn(s, s1));
		return (0);



}
