#include <minishell.h>

size_t	count(t_tokens *tokens)
{
	size_t	i;

	i = 0;
	while (tokens != NULL && isseparator(tokens->label) == 0)
	{
		tokens = tokens->next;
		i++;
	}
	return (i);
}

char **list_to_args(t_tokens *tokens)
{
	char    **args;
	size_t      i;

	i = 0;
	args = malloc(sizeof(char *) * (count(tokens) + 1));
	while (tokens != NULL && isseparator(tokens->label) == 0)
	{
		args[i] = ft_strdup(tokens->token);
		tokens = tokens->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

int isbuiltin(char *cmd)
{
    if (ft_strcmp(cmd, "echo") == 0 ||
		ft_strcmp(cmd, "cd") == 0 ||
		ft_strcmp(cmd, "pwd") == 0 ||
		ft_strcmp(cmd, "export") == 0 ||
		ft_strcmp(cmd, "unset") == 0 ||
		ft_strcmp(cmd, "env") == 0 ||
		ft_strcmp(cmd, "exit") == 0)
        return (1);
    return (0);
}

void    execin(char **args, t_vars *vars)
{
    if (ft_strcmp(*args, "echo") == 0)
        echo(args + 1);
	else if (ft_strcmp(*args, "cd") == 0)
		cd(args + 1, vars->envs_a);
	else if (ft_strcmp(*args, "pwd") == 0)
		pwd(args + 1, vars->envs_a);
	else if (ft_strcmp(*args, "export") == 0)
		export(args + 1, vars->envs_a);
	else if (ft_strcmp(*args, "unset") == 0)
		unset(args + 1, vars);
	else if (ft_strcmp(*args, "env") == 0)
		env(args, vars->envs_a);
	else
		exits(args);
}

void	exec(t_tokens *tokens, t_vars *vars)
{
	char	**args;

	// /usr/bin/ls
	args = list_to_args(tokens);
    if (isbuiltin(*args))
        execin(args, vars);
    else
	{
		*args = ft_strjoin("/usr/bin/", *args);
        execve(*args, args, __environ);
		perror(strerror(errno));
	}
}
