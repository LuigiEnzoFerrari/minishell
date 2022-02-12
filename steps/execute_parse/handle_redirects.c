#include <minishell.h>

int has_redirect(int *labels)
{
    size_t  i;

    i = 0;
    while (labels[i] != 0)
    {
        if (labels[i] == DOUBLE_REDIRECT || labels[i] == SINGLE_REDIRECT
            || labels[i] == SINGLE_REDIRECT_IN)
            return (1);
        i++;
    }
    return (0);
}

void redirects(char *args, int flag, int std_fd)
{
	int fd;

	fd = open(args, flag, 0664);
	dup2(fd, std_fd);
    close(fd);
}

static size_t  how_many_non_redirects(char **args, int *labels)
{
	size_t  i;
    size_t  n;

	i = 0;
    n = 0;
	while (args[i] != NULL)
	{
		if (labels[i] == DOUBLE_REDIRECT || labels[i] == SINGLE_REDIRECT
        || labels[i] == SINGLE_REDIRECT_IN)
            i++;
        else
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
    ft_putnbr_fd(size, 1);
    ft_putstr("\n");
	new_args = malloc(sizeof(char *) * (size + 1));
	while (args[j] != NULL)
	{
		if (labels[j] == DOUBLE_REDIRECT || labels[j] == SINGLE_REDIRECT
            || labels[j] == SINGLE_REDIRECT_IN)
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
