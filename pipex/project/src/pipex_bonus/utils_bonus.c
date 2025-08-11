/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:45:25 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/03 21:45:25 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

int	open_file(char *av, int mode)
{
	int		fd;

	fd = 0;
	if (mode == 0)
		fd = open(av, O_RDONLY, 0644);
	else if (mode == 1)
		fd = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		fd = open(av, O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (fd);
}

int	child_process(char	*av, char **env, int input_fd)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) < 0)
		error_exit("pipe failed", 1, NULL);
	pid = fork();
	if (pid < 0)
		error_exit("fork failed", 1, NULL);
	if (pid == 0)
	{
		close(pipefd[0]);
		if (input_fd < 0)
		{
			close(pipefd[1]);
			exit (1);
		}
		dup2(input_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(input_fd);
		close(pipefd[1]);
		execute_cmd(av, env);
	}
	close(input_fd);
	close(pipefd[1]);
	return (pipefd[0]);
}
