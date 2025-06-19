/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:15:58 by jaemyu            #+#    #+#             */
/*   Updated: 2025/06/15 00:15:58 by jaemyu           ###   ########.fr       */
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

void	child1(char **argv, char **env, int *fds);
void	child2(char **argv, char **env, int *fds);
int	    main(int argc, char **argv, char **env);
char	*path_search(char *cmd, char **env);
void    error(int i);
void    error_free(char **cmd, int i) ;
void	ft_exec(char *cmd, char **env);

#endif