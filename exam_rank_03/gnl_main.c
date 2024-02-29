/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:14:21 by brandebr          #+#    #+#             */
/*   Updated: 2024/02/29 11:05:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int	main(int argc, char **argv)
{
	(void)argc;

	int	fd = open(argv[1], O_RDONLY);
	char	*line = get_next_line(fd);
	
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
