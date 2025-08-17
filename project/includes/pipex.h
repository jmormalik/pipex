/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:43:37 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/11 16:54:52 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	error_exit(const char *msg, int exit_code, char **splited);
void	free_split(char **split);
char	**find_paths(char **env);
char	*get_cmd_path(char **paths, char *cmd);
void	execute_cmd(char *argv, char **env);

#endif
