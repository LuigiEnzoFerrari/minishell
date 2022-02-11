#include <minishell.h>

int	count_output_redirects(int *labels)
{
	int counter;
	int i;

	i = 0;
	counter = 0;
	while(labels[i] != 0)
	{
		if(labels[i] == 5 || labels[i] == 6)
			counter++;
		i++;
	}
	return counter;
}

int first_redirect_position(char **args)
{
	int i = 0;

	while((ft_strcmp(args[i],">") && ft_strcmp(args[i],">>")))
		i++;
	return (i);
}

char	**remove_redirect_and_file_name(char **args, int i)
{
	char **new_args = NULL;
	int args_len = 0;
	int j = 0;
	int k = 0;

	while(args[args_len] != NULL)
		args_len++;
	new_args = (char **)malloc(sizeof(char *) * (args_len - 1));

	while(j < args_len)
	{
		if(j != i && (j != i + 1))
			new_args[k++] = ft_strdup(args[j]);
		j++;
	}

	new_args[args_len - 2] = NULL; //maybe wrong?
	return new_args;
}

char	**new_cmd_args(char **args)
{
	char **new_args;
	int i = 0;

	i = first_redirect_position(args);
	new_args = remove_redirect_and_file_name(args, i);
	ft_arrayfree(args);
	return new_args;
}

void	case_redirect(int index, int *pidfd, int storeIN, t_cmds  *cmds)
{
	int  i = 0;
	int fd;
	int number_of_redirects = count_output_redirects(cmds->labels);
	while(number_of_redirects && cmds->args[i])
	{
		if(!ft_strcmp(cmds->args[i],">") || !ft_strcmp(cmds->args[i],">>"))
		{
			if(!ft_strcmp(cmds->args[i],">"))
				fd = open(cmds->args[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0664);
			if(!ft_strcmp(cmds->args[i],">>"))
				fd = open(cmds->args[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0664);
			if(number_of_redirects == 1)
				dup2(fd, OUT);
			cmds->args = new_cmd_args(cmds->args);
			number_of_redirects--;
			i -= 2;
		}
		i++;
	}
}