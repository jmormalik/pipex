/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:13:31 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/13 17:00:13 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one(char **av, char **env, int *pipe_fd)
{
	int	infile;

	close(pipe_fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		error_exit("infile open failed", 1, NULL);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(infile);
	close(pipe_fd[1]);
	execute_cmd(av[2], env);
}

static void	child_two(char **av, char **env, int *pipe_fd)
{
	int	outfile;

	close(pipe_fd[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("outfile open failed", 1, NULL);
	dup2(outfile, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(outfile);
	close(pipe_fd[0]);
	execute_cmd(av[3], env);
}

static int	wait_and_close(pid_t pid1, pid_t pid2, int *pipe_fd)
{
	int		status;

	status = 0;
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (WTERMSIG(status) + 128);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
		error_exit("pipe failed", 1, NULL);
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork failed", 1, NULL);
	if (pid1 == 0)
		child_one(av, env, pipe_fd);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork failed", 1, NULL);
	if (pid2 == 0)
		child_two(av, env, pipe_fd);
	return (wait_and_close(pid1, pid2, pipe_fd));
}
