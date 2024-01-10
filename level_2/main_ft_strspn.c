/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strspn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:53:54 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/07 19:05:03 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept);

int	main(void)
{
		char *s = "Once upone was a big fat duck";
		char *acc = "eup aocdfmnOib taw";
		 

		printf("%zu\n", strspn(s, acc));
		printf("%zu\n",ft_strspn(s, acc));
}

