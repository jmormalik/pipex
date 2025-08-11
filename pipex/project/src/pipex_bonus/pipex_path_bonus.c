/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:10:15 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/04 18:10:15 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_split(char **split)
{
	int		i;

	if (! split)
		return ;
	i = 0;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

char	**find_paths(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (ft_split(*env + 5, ':'));
		env++;
	}
	ft_print_error("Could not find environment variable PATH");
	return (NULL);
}

char	*get_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (path && path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}

void	execute_cmd(char *argv, char **env)
{
	char	**path;
	char	**cmd_args;
	char	*cmd_path;

	path = find_paths(env);
	if (!*argv || !*path)
	{
		free_split(path);
		write(2, "permission denied\n", 18);
		exit(126);
	}
	cmd_args = ft_split(argv, ' ');
	if (!cmd_args || !*cmd_args)
	{
		free_split(path);
		error_exit("command not found", 127, cmd_args);
	}
	cmd_path = get_cmd_path(path, cmd_args[0]);
	free_split(path);
	if (!cmd_path)
		error_exit("command not found", 127, cmd_args);
	execve(cmd_path, cmd_args, env);
	free(cmd_path);
	error_exit("execve failed", 1, cmd_args);
}
