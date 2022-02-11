#include <minishell.h>

int has_redirect(int *labels)
{
    size_t  i;

    i = 0;
    while (labels[i] != 0)
    {
        if (labels[i] == DOUBLE_REDIRECT || labels[i] == SINGLE_REDIRECT)
            return (1);
        i++;
    }
    return (0);
}

void redirect_output(char *args, int flag)
{
	int fd;

	fd = open(args, flag, 0664);
	dup2(fd, OUT);
    close(fd);
}

static size_t  how_many_non_redirects(char **args, int *labels)
{
	size_t  i;
    size_t  n;

	i = 0;
	while (args[i] != NULL)
	{
		if (labels[i] != DOUBLE_QUOTE && labels[i] != SINGLE_REDIRECT)
			n++;
        i++;
	}
	return (n);
}

char    **remove_redirects(char **args, int *labels)
{
	char    **new_args;
	size_t  size;
	size_t  i;
	size_t	j;

	i = 0;
	j = 0;
	size = how_many_non_redirects(args, labels);
	new_args = malloc(sizeof(char *) * (size + 1));
	while (args[j] != NULL)
	{
		if (labels[j] == DOUBLE_REDIRECT || labels[j] == SINGLE_REDIRECT)
        {
			j += 2;
			continue ;
        }
		new_args[i] = ft_strdup(args[j]);
		i++;
		j++;
	}
    new_args[i] = NULL;
	ft_arrayfree(args);
	return (new_args);
}
