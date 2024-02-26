/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:54:03 by brandebr          #+#    #+#             */
/*   Updated: 2024/02/26 11:19:27 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	pud(long long int number,  int base, int *len)
{
	char	*hex = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*len += write(1, "-", 1); 
	}
	if (number >= base)
		pud((number / base), base, len);
	*len += write(1, &hex[number % base], 1);
}

int ft_printf(const char *str, ... )
{
	int	len = 0;
	va_list	ptr;

	va_start(ptr, str);

	while (*str)
	{
		if ((*str == '%') && (
					(*(str + 1) == 's') ||
					(*(str + 1) == 'd') ||
					(*(str + 1) == 'x')))
		{
			str++;
			if (*str == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			else if (*str == 'd')
				pud((long long int)va_arg(ptr, int), 10, &len);
			else if (*str == 'x')
				pud((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, str, 1);
		str++;

	}
	return (va_end(ptr), len);
}
