/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:51:20 by hekim             #+#    #+#             */
/*   Updated: 2025/01/30 00:51:22 by hekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_get_word(char const **s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!word)
		return ((void *)0);
	i = 0;
	while (**s && **s != c)
		word[i++] = *(*s)++;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	count;

	if (s == (void *)0)
		return ((void *)0);
	count = ft_word_count(s, c);
	res = (char **)ft_calloc(sizeof(char *), (count + 1));
	if (!res)
		return ((void *)0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		res[i] = ft_get_word(&s, c);
		if (!res[i++])
		{
			while (--i > 0)
				free(res[i - 1]);
			free(res);
			return ((void *)0);
		}
	}
	return (res);
}
