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
#include <stdio.h>

void    error_exit(const char *msg, int exit_code, char **splited)
{
	if (splited)
		free_split(splited);
    perror(msg);
	printf("%d", errno);
	if(!exit_code)
		exit(errno);
    exit(exit_code);
}