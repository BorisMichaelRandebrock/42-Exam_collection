/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:10:39 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:34:43 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	int	len;

	char *str = "Hello World!"; // 12 characters
	len = ft_strlen(str);
	printf("len: %d\n", len);
	return (0);
}
