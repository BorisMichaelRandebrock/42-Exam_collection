/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microhell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:58:39 by brandebr          #+#    #+#             */
/*   Updated: 2024/03/12 14:23:36 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Function to write an error message to standard error (file descriptor 2)
int err(char *str) 
{
    while (*str)
        write(2, str++, 1); // Writing each character of the string to stderr
    return 1;
}

// Function to change the current directory
int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n"); // Return an error if the argument count is not 2
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"); // Return an error if directory change fails
    return 0; // Return 0 on success
}

// Function to execute a command
int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|"); // Check if a pipe is present in the command

    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n"); // Return an error if pipe creation fails

    int pid = fork(); // Create a child process
    if (!pid) 
    {
        argv[i] = 0; // Set the element after the pipe or semicolon to null
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n"); // Return an error if pipe redirection or closing fails
        execve(*argv, argv, envp); // Execute the command
        return err("error: cannot execute "), err(*argv), err("\n"); // Return an error if execution fails
    }

    waitpid(pid, &status, 0); // Wait for the child process to finish
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n"); // Return an error if pipe redirection or closing fails
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i; // Move the argv pointer forward by i
            i = 0; // Reset i to 0
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++; // Find the next pipe or semicolon or end of arguments
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i); // Execute cd command
            else if (i)
                status = exec(argv, envp, i); // Execute other commands
        }
    }
    return status; // Return the status of the last executed command
}
