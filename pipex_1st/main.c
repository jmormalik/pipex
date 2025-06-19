#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_word_dup(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	**ft_split_word(char **arr, char const *s, char c)
{
	const char	*start;
	size_t		len;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			len = s - start;
			arr[i] = ft_word_dup(start, len);
			if (!arr[i++])
			{
				ft_free(arr, i);
				return (NULL);
			}
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	return (ft_split_word(arr, s, c));
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*result;
	size_t		r_len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	r_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(r_len + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char *path_search(char *argv, char **splitcmd)
{
    char *temp;
    char *fullpath;
    int i;

    i = 0;
    while (splitcmd[i] != NULL)
    {
        temp = ft_strjoin(splitcmd[i], "/");
        if (!temp)
            return (NULL);
        fullpath = ft_strjoin(temp, argv);
        free(temp);
        if (!fullpath)
            return (NULL);
        if (access(fullpath, X_OK) == 0)
            return (fullpath);
        free(fullpath);
        i++;
    }
    return (NULL);
}

void get_path(char **argv, char **env)
{
    char **split;
    char *path;
    path = NULL;

    int i = 0;
    while (env[i] != NULL)
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            path = env[i] + 5;
            break;
        }
        i++;
    }

    if (path == NULL)
        return;

    split = ft_split(path, ':');
    if (!split)
        return;

    char *found_path = path_search(argv[1], split);

    if (found_path)
        printf("%s\n", found_path);
    else
        printf("command not found\n");

    for (int i = 0; split[i] != NULL; i++)
        free(split[i]);
    free(split);

    if (found_path)
        free(found_path);
}



int main(int argc, char **argv,char **env)
{
	(void)argc;
	(void)argv;
	get_path(argv, env);
    return 0;
}

