/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:10:27 by brandebr          #+#    #+#             */
/*   Updated: 2024/01/12 18:34:35 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	put_char(char c);

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(argv[1]);
	put_char('\n');
	return (0);
}
