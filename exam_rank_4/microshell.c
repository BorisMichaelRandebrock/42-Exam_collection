/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:25:56 by brandebr          #+#    #+#             */
/*   Updated: 2024/07/04 18:10:53 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

static int	er(char *s, char *argv)
{
	while (*s)
		write(2, s++, 1);
	if (argv)
	{
		write(2, " ", 1);
		while (*argv)
			write(2, argv++, 1);
	}
	write(2, "\n", 1);
	return (1);
}

static int	cd(char **argv, int	i)
{
	if (i != 2)
		return er("error: cd: bad arguments", NULL);
	else if (chdir(argv[1]) == -1)
		return er("error: cd: cannot change directory to", argv[1]);
	return (0);
}

static int	exec(char **argv, char **envp, int i)
{
	int		status;
	int		fd[2];
	int		pipes = (argv[i] && !strcmp(argv[i], "|"));

	if (pipes && pipe(fd) == -1)
		return (er("error: fatal", NULL));
	int		pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (pipes && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return (er("error: fatal", NULL));
		execve(*argv, argv, envp);
		return (er("error: cannot execute", *argv));
	}
	waitpid(pid, &status, 0);
	if (pipes && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (er("error: fatal", NULL));
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	int		status = 0;

	while (*argv && *(argv + 1))
	{
		argv++;
		int		i = 0;
		while (argv[i] && strcmp(argv[i], "|")  && strcmp(argv[i], ";"))
			i++;
		if (strcmp(*argv, "cd") == 0)
			status = cd(argv, i);
		else if (i)
			status = exec(argv, envp, i);
		argv += i;
	}
	return (status);
}
// alternative.. shorter version
/*
static int	er(char *s, char *argv)
{
	while (*s)
		write(2, s++, 1);
	if (argv)
		while (*argv)
			write(2, argv++, 1);
	write(2, "\n", 1);
	return (1);
}

static int	cd(char **argv, int i)
{
	if (i != 2)
		return (er("error: cd: bad arguments", NULL));
	else if (chdir(argv[1]) == -1)
		return (er("error: cd: cannot change directory to ", argv[1]));
	return (0);
}

static int	exe(char **argv, char **envp, int i)
{

	int		status;
	int		fd[2];
	int		pipes = (argv[i] && !strcmp(argv[i], "|"));

	if (pipes && pipe(fd) == -1)
		return (er("error: fatal", NULL));
	int		pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (pipes && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return (er("error: fatal", NULL));
		execve(*argv, argv, envp);
		return (er("error: cannot execute ", *argv));
	}
	waitpid(pid, &status, 0);
	if (pipes && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (er("error: fatal", NULL));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;

	while (*argv && *(argv + 1))
	{
		argv++;
		int		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			cd(argv, i);
		else if (i)
			exe(argv, envp, i);
		argv += i;
	}
	return (0);
}
*/

