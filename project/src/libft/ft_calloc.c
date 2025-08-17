/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:08:56 by hekim             #+#    #+#             */
/*   Updated: 2025/04/02 02:09:09 by hekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*cal;

	if (size && nmemb > (((size_t)-1) / size))
		return ((void *)0);
	total = nmemb * size;
	cal = malloc(total);
	if (!cal)
		return ((void *)0);
	ft_bzero(cal, total);
	return (cal);
}
