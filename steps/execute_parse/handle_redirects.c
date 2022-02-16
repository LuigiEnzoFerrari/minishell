#include <minishell.h>

int has_redirect(int *labels)
{
    size_t  i;

    i = 0;
    while (labels[i] != 0)
    {
        if (labels[i] == DOUBLE_REDIRECT || labels[i] == SINGLE_REDIRECT
            || labels[i] == SINGLE_REDIRECT_IN || labels[i] == HEARDOC)
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

void hear_document(char *args, int flag, int std_fd)
{
	int     write_fd;
    int     read_fd;
    char    *line;

    // Criando arquivo temporario
	write_fd = open(args, flag, 0664);
    while (42)
    {
        line = readline("> ");
        if (ft_strcmp(line, args) == 0)
        {
            free(line);
            break ;
        }
        // Escrevendo no arquivo
        ft_putendl_fd(line, write_fd);
        free(line);
    }
    read_fd = open(args, O_RDONLY);
    dup2(read_fd, std_fd);
    close(write_fd);
    close(read_fd);
	unlink(args);
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
        || labels[i] == SINGLE_REDIRECT_IN  || labels[i] == HEARDOC)
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
	new_args = malloc(sizeof(char *) * (size + 1));
	while (args[j] != NULL)
	{
		if (labels[j] == DOUBLE_REDIRECT || labels[j] == SINGLE_REDIRECT
            || labels[j] == SINGLE_REDIRECT_IN  || labels[i] == HEARDOC)
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

void	case_redirect(int saveIN, t_cmds  *cmds)
{
	int  i = 0;
	int fd;

	while(cmds->args[i] != NULL)
	{
		if (cmds->labels[i] == SINGLE_REDIRECT)
			redirects(cmds->args[i + 1],  O_WRONLY | O_CREAT | O_TRUNC, OUT);
		else if (cmds->labels[i] == DOUBLE_REDIRECT)
			redirects(cmds->args[i + 1],  O_WRONLY | O_CREAT | O_APPEND, OUT);
		else if (cmds->labels[i] == SINGLE_REDIRECT_IN)
			redirects(cmds->args[i + 1],  O_RDONLY, IN);
		else if (cmds->labels[i] == HEARDOC)
			hear_document(cmds->args[i + 1], O_WRONLY | O_CREAT, saveIN);
		i++;
	}
	cmds->args = remove_redirects(cmds->args, cmds->labels);
    if (cmds->args[0] == NULL)
        exit(errno);
}
