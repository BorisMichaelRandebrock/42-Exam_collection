/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:32:00 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 19:04:07 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
		size_t count = 0;
		while (*s)
		{
				int j = 0;
				while (accept[j])
				{
						if (*s == accept[j])
						{
								count++;
								break;
						}
						j++;
				}
				if (!accept[j])
						break;
				s++;
		}
		return count;
}
/*
   char	*ft_strchr(const char *s, int c)
   {
   while (*s != '\0')
   {
   if (*s == c)
   return ((char *)s);
   ++s;
   }
   return (0);
   }

   size_t	ft_strspn(const char *s, const char *accept)
   {
   size_t i = 0;

   while (s[i] != '\0')
   {
   if (ft_strchr(accept, s[i]) == 0)
   break;
   ++i;
   }
   return (i);
   }
   */
/*
   size_t	ft_strspn(const char *s, const char *accept)
   {
   size_t		i;
   size_t		j;
   size_t		c;

   i = 0;
   c = 0;
   while (s[i])
   {
   j = 0;
   while (accept[j])
   {
   if (s[i] == accept[j])
   {
   c++;
   break;
   }

   j++;
   }
   i++;
   }
   return (c);
   }







   size_t	ft_strspn(const char *s, const char *accept)
   {
   size_t	i;
   size_t	c;

   i = 0;
   c = 0;
   while (s[i])
   {
   size_t	j = 0;
   while (accept[j])
   {
   if (s[i] == accept[j])
   {
   c++;
   break ;
   }
   j++;
   }
   i++;
   }
   return (c);
   }*/
/*
   int		main(void)
   {
   char	*s = "some";
   char	*c = "eabocmhkldnis";
   printf("%zu\n\a", strspn(s, c));
   printf("%zu\n", ft_strspn(s, c));
   return (0);
   }
   */
