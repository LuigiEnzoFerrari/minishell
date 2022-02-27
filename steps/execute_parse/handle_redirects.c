#include <minishell.h>

int	redirects(char *args, int flag, int std_fd)
{
	int	fd;

	fd = open(args, flag, 0664);
	if (fd < 0)
	{
		perror(strerror(errno));
		return (1);
	}
	dup2(fd, std_fd);
	close(fd);
	return (0);
}

static size_t	how_many_non_redirects(char **args, int *labels)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (args[i] != NULL)
	{
		if (labels[i] == DOUBLE_REDIRECT
			|| labels[i] == SINGLE_REDIRECT
			|| labels[i] == SINGLE_REDIRECT_IN
			|| labels[i] == HEREDOC)
			i++;
		else
			n++;
		i++;
	}
	return (n);
}

char	**remove_redirects(char **args, int *labels)
{
	char	**new_args;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = how_many_non_redirects(args, labels);
	new_args = malloc(sizeof(char *) * (size + 1));
	while (args[j] != NULL)
	{
		if (labels[j] == DOUBLE_REDIRECT || labels[j] == SINGLE_REDIRECT
			|| labels[j] == SINGLE_REDIRECT_IN || labels[i] == HEREDOC)
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

void	case_redirect(t_cmds *cmds)
{
	size_t	i;

	i = 0;
	while (cmds->args[i] != NULL)
	{
		if (cmds->labels[i] == SINGLE_REDIRECT)
			redirects(cmds->args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, OUT);
		else if (cmds->labels[i] == DOUBLE_REDIRECT)
			redirects(cmds->args[i + 1], O_WRONLY
				| O_CREAT | O_APPEND, OUT);
		else if (cmds->labels[i] == SINGLE_REDIRECT_IN)
			redirects(cmds->args[i + 1], O_RDONLY, IN);
		else if (cmds->labels[i] == HEREDOC)
			here_document(cmds->args[i + 1], O_WRONLY | O_CREAT, IN);
		i++;
	}
	cmds->args = remove_redirects(cmds->args, cmds->labels);
	if (cmds->args[0] != NULL)
		return ;
	ft_arrayfree(cmds->args);
	cmds->args = NULL;
}
