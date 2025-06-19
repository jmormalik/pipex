/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:01:57 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/14 22:44:46 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

void	child1(char **argv, char **envp, int *fds);
void	child2(char **argv, char **envp, int *fds);
void	pipe_make(char **argv, char **envp);
int		main(int argc, char **argv, char **envp);
char	*path_search(char *argv, char **splitcmd);
void	error(void);
void	ft_exec(char *argv, char **env);
char	*ft_free(char *str);
void	free_split(char **spl);

#endif