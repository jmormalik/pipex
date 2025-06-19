/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:28:19 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/14 22:44:47 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_search(char *argv, char **splitcmd)
{
	char	*temp;
	char	*fullpath;
	int		i;

	i = 0;
	while (splitcmd[i])
	{
		temp = ft_strjoin(splitcmd[i], "/");
		if (!temp)
			return (NULL);
		fullpath = ft_strjoin(temp, argv);
		if (!fullpath)
			return (ft_free(fullpath));
		if (access(fullpath, F_OK) == 0)
		{	
			free(temp);
			return (fullpath);
		}
		free(temp);
		free(fullpath);
		i++;
	}
	return (NULL);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

void	error(void)
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}

void	free_split(char **spl)
{
	int	i;

	i = 0;
	while(spl[i])
		free(spl[i++]);
	free(spl);
}

void	ft_exec(char *argv, char **env)
{
	int		i;
	char	*splitcmd;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(argv, ' ');
	while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
		i++;
	if (!env[i])
		error();
	splitcmd = ft_split(env[i] + 5, ':');
	path = path_search(argv, splitcmd);
	if (!path)
		free_split(splitcmd);
	if (execve(path, cmd, env) == -1)
		error();
}
