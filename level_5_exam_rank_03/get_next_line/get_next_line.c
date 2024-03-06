/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:24:44 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/05 12:05:47 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*del_line(char *buff)
{
	int i = 0, j = 0;

	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	char	*result = malloc(ft_strlen(buff) -i + 1);
	i++;
	while (buff[i])
		result[j++] = buff[i++];
	result[j] = '\0';
	free(buff);
	return (result);
}

char	*ge_line(char *buff)
{
	int	i = 0;

	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	char	*result = malloc(i + 1);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		result[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
		return (result);
	}
	else
		result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i = 0, j = 0;

	char *result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
	{
		while (s1[i])
			result[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

int	is_line(char *store)
{
	int i = 0;

	while (store[i])
	{
		if (store[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char	*store = NULL;
	char	buffer[BUFFER_SIZE + 1] = {0};
	char	*line = NULL;
	int	rd = 1;

	while (!is_line(buffer) && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			if (store)
			{
				free(store);
				store = NULL;
			}
			return (NULL);
		}
		buffer[rd] = '\0';
		store = ft_strjoin(store, buffer);
	}
	line = ge_line(store);
	store = del_line(store);
	
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
