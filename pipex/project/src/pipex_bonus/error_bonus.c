/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:45:20 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/03 21:45:20 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(const char *msg, int exit_code, char **splited)
{
	if (splited)
		free_split(splited);
	perror(msg);
	if (! exit_code)
		exit(errno);
	exit(exit_code);
}

void	ft_perror(void)
{
	perror(NULL);
	exit(errno);
}

void	ft_print_error(const char *msg)
{
	if (write(2, "pipex: ", 7) == -1)
		ft_perror();
	if (write(2, msg, ft_strlen(msg)) == -1)
		ft_perror();
	if (write(2, "\n", 1) == -1)
		ft_perror();
	exit(1);
}
