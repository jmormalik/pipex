/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:18:33 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/15 00:18:33 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_search(char *cmd, char **env)
{
	char    *path;
	char    **paths;
	int     i;
	char	*full_path;

	i = 0;
	while (*env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	error_free(paths, 1);
	return (NULL);
}

void    error(int i)
{
    if (i)
    {
        ft_putstr_fd("ERROR: BAD ARGUMENT\n", 2);
		ft_putstr_fd("ex) ./pipex  <file1> <cmd1> | <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
    }
    else if(i == 0)
    {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
}

void    error_free(char **cmd, int i) 
{
	int index;

	if (!cmd)
		error(0);
	index = 0;
	if (i)
	{
    	free(cmd);
    	error(0);
	}
	else if (i == 0)
	{
		while(cmd[index])
			free(cmd[index++]);
		free(cmd);
		error(0);
	}
}

void	ft_exec(char *cmd, char **env)
{
    char    **split_cmd;
    char    *path;

    split_cmd = ft_split(cmd, ' ');
    if (!split_cmd || !split_cmd[0])
		error_free(split_cmd, 1);
	path = path_search(split_cmd[0], env);
	if (!path)
		error_free(split_cmd, 0);
	if (execve(path, split_cmd, env) == -1)
		error_free(split_cmd, 0);	
}
