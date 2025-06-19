/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:06:13 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/16 18:06:13 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **argv, char **env, int *fds)
{
	int	infile;

	close(fds[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_free(NULL, 0);
	dup2(infile, 0);
	dup2(fds[1], 1);
	close(infile);
	close(fds[1]);
	ft_exec(argv[2], env);
}

void	child2(char **argv, char **env, int *fds)
{
	int	outfile;

	close(fds[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_free(NULL, 0);
	dup2(outfile, 1);
	dup2(fds[0], 0);
	close(outfile);
	close(fds[0]);
	ft_exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	fds[2];
	pid_t	pid[2];

	if (argc != 5)
		error_free(NULL, 1);
	if (pipe(fds) == -1)
		error_free(NULL, 0);
	if ((pid[0] = fork()) == -1)
		error_free(NULL, 0);
	if (pid[0] == 0)
		child1(argv, env, fds);
	if ((pid[1] = fork()) == -1)
	{
		waitpid(pid[0], NULL, 0);
		error_free(NULL, 0);
	}
	if (pid[1] == 0)
		child2(argv, env, fds);
	close(fds[0]);
	close(fds[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}