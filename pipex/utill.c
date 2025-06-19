/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:06:31 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/16 18:06:31 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_split(char *path)
{
	int	i;

	i = 0;
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
	if (!cmd && i)
    {
        ft_putstr_fd("ERROR: BAD ARGUMENT\n", 2);
		ft_putstr_fd("ex) ./pipex  <file1> <cmd1> | <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
    }
    else if(!cmd && i == 0)
    {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
	else if (cmd && i)
	{
    	free(cmd);
    	error_free(NULL, 0);
	}
	else if (cmd && i == 0)
	{
		while(*cmd)
			free(*cmd++);
		free(cmd);
		error_free(NULL, 0);
	}
}

void    ft_exec(char **cmd, char **env)
{
    int		i;
    char	**split_cmd;
	char	*path;

	i = 0;
	split_cmd = ft_split(cmd, ' ');
	if(!split_cmd || split_cmd[0])
		error_free(split_cmd, 1);
	while (*env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		error_free(NULL, 0);
	path = ft_split(env[i] + 5, ":");
	if (!path || !path[0])
		error_free(path, 1);
	path = path_split(path);
	if (!path)
		error_free(path, 1);
	if (execve(path, split_cmd, env) == -1)
		error_free(split_cmd, 0);
}
