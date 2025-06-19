/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:31:13 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/14 22:25:26 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **argv, char **envp, int *fds)
{
	int	infile;

	close(fds[0]);
	infile = open(argv[1], O_RDONLY);
	dup2(infile, 0);
	dup2(fds[1], 1);
	close(0);
	ft_exec(argv[2], envp);
}

void	child2(char **argv, char **envp, int *fds)
{
	int	outfile;

	close(fds[1]);
	outfile = open(argv[0], O_WRONLY | O_CREAT | O_TRUNC);
	dup2(outfile, 1);
	dup2(fds[0], 0);
	close(1);
	ft_exec(argv[3], envp);
}

void	pipe_make(char **argv, char **envp)
{
	pid_t	pid[2];
	int		fds[2];

	if (pipe(fds) == -1)
		error();
	pid[0] = fork();
	if (pid[0] == -1)
		error();
	if (pid[0] == 0)
		child1(argv, envp, fds);
	pid[1] = fork();
	if (pid[1] == -1)
	{
		waitpid(pid[0], NULL, 0);
		error();
	}
	if (pid[1] == 0)
		child2(argv, envp, fds);
	waitpid(pid[1], NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipe_make(argv, envp);
	else
	{
		ft_putstr_fd("ERROR: BAD ARGUMENT\n", 2);
		ft_putstr_fd("ex) ./pipex  <file1> <cmd1> | <cmd2> <file2>\n", 1);
	}
}
