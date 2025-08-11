/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:59:18 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/11 17:20:37 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	error_exit(const char *msg, int exit_code, char **splited);
void	execute_cmd(char *argv, char **env);
void	free_split(char **split);
char	**find_paths(char **env);
char	*get_cmd_path(char **path, char *cmd);
int		open_file(char *av, int mode);
int		child_process(char	*av, char **env, int input_fd);
void	ft_print_error(const char *msg);
void	ft_perror(void);

#endif
