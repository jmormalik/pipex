/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:44:45 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/03 21:44:45 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static pid_t	outfile(char *av, char **env, int input_fd, int out_fd)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		error_exit("fork failed", 1, NULL);
	if (pid == 0)
	{
		if (out_fd < 0)
		{
			close(input_fd);
			exit (1);
		}
		dup2(input_fd, STDIN_FILENO);
		dup2(out_fd, STDOUT_FILENO);
		close(input_fd);
		close(out_fd);
		execute_cmd(av, env);
	}
	close(input_fd);
	close(out_fd);
	return(pid);
}

static int	wait_wait(pid_t end_pid)
{
	int		status;
	int		end_status;
	pid_t	pid;

	status = 0;
	pid = 1;
	while(!(pid < 0))
	{
		pid = wait(&status);
		if (pid == end_pid)
			end_status = status;
	}
	if(WIFEXITED(end_status))
		return (WEXITSTATUS(end_status));
	else
		return (WTERMSIG(end_status) + 128);
}

static int	here_doc(char **av, int len)
{
	int		pipe_fd[2];
	char	*str;

	if (pipe(pipe_fd) < 0)
		error_exit(NULL, 0, NULL);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break;
		else if (ft_strncmp(str, av[2], len) == 0 && av[len] == '\n')
		{
			free(str);
			break;
		}
		write(pipe_fd[1], str, ft_strlen(str));
		free(str);
	}
	close(pipe_fd[1]);
	get_next_line(-1);
	return (pipe_fd[0]);
}

int	main(int ac, char **av, char **env)
{
	int		inout_fd[2];
	int		input_fd;
	int		i;
	pid_t	end_pid;

	i = 2;
	if (ac > 4)
	{
		if (ac > 5 && ft_strncmp(av[2], "here_doc", 9) == 0 && i++)
			inout_fd[0] = here_doc(av, ft_strlen(av[2]));
		else
			inout_fd[0] = open_file(av[1], 0);
		input_fd = inout_fd[0];
		while(i < ac - 2)
			input_fd = child_process(av[i++], env, input_fd);
		inout_fd[1] = open_file(av[ac - 1], 1);
		end_pid = outfile(av[ac - 2], env, input_fd, inout_fd[1]);
		return (wait_wait(end_pid));
	}
	else
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(EXIT_FAILURE);
}
