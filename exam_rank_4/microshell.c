/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:16:15 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/08 19:13:12 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int		i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_put_fd(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	ft_execute(char *argv[], int i, int tmp_fd, char *env[])
{
	argv[i] = NULL;
	dup2(tmp_fd, 0);
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_put_fd("error cannot execute ");
	ft_put_fd(argv[0]);
	ft_put_fd("\n");
	return (1);
}

int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int		fd[2];
	int		tmp_fd;
	int		pid;
	(void)argc;
	i = 0;
	tmp_fd = dup(0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_put_fd("error: cd: bad arguments\n");
			else if (chdir(argv[1]) == -1)
			{
				ft_put_fd("error: cd: cannot change directory to ");
				ft_put_fd(argv[1]);
				ft_put_fd("\n");
			}
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if (pid == -1)
				return 1;
			if (pid == 0)
			{
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				waitpid(pid, NULL, WUNTRACED);
				tmp_fd = dup(0);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd[1], 1);
				close(fd[0]);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}

