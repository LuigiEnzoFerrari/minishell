#include <minishell.h>

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

void    execute_builtin(char **args, t_env_vars *vars)
{
    if (ft_strcmp(*args, "echo") == 0)
        builtin_echo(args + 1);
	else if (ft_strcmp(*args, "cd") == 0)
		builtin_cd(args + 1, vars->global_vars);
	else if (ft_strcmp(*args, "pwd") == 0)
		builtin_pwd(args + 1, vars->global_vars);
	else if (ft_strcmp(*args, "export") == 0)
		builtin_export(args + 1, vars);
	else if (ft_strcmp(*args, "unset") == 0)
		builtin_unset(args + 1, vars);
	else if (ft_strcmp(*args, "env") == 0)
		builtin_env(args, vars->global_vars);
	else
		builtin_exit(args, vars);
}

void    execute_builtout(char **args, t_env_vars *vars)
{
	if(!ft_strcmp(*args, ""))
		return ;
	*args = ft_joindel(ft_strdup("/usr/bin/"), *args);
	execve(*args, args, __environ);
	perror(strerror(errno));
}

void	case_pipe(int index, int *pidfd, int *store, t_cmds  *cmds)
{
	if(index == 0)
	{
		if(cmds->next != NULL)
			dup2(pidfd[OUT], OUT);
	}
	else if(cmds->next == NULL)
		dup2(store[IN], IN);
	else 
	{
		dup2(pidfd[OUT], OUT);
		dup2(store[IN], IN);
	}
}
char	**new_cmd_arg(char **args)
{
	char **new_args;
	int i = 0;
	int j = -1;
	//find redirect
	if(!ft_strcmp(args[0],">") || !ft_strcmp(args[0],">>"))
	{
		new_args = (char **)malloc(sizeof(char *) * 2);
		new_args[0] = ft_strdup("");
		new_args[1] = NULL;
		return new_args;
	}
	while((ft_strcmp(args[i],">") && ft_strcmp(args[i],">>")))
		i++;
	new_args = (char **)malloc(sizeof(char *) * (i + 1));
	new_args[i] = NULL;
	while(++j < i)
		new_args[j] = ft_strdup(args[j]);
	return new_args;
}

void	case_redirect(int index, int *pidfd, int storeIN, t_cmds  *temp)
{
	int  i = 0;
	int fd;
	while(temp->args[i])
	{
		if(!ft_strcmp(temp->args[i],">"))
		{
			fd = open(temp->args[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0664);
			dup2(fd, OUT);
			temp->args = new_cmd_arg(temp->args);
			return ;
		}
		if(!ft_strcmp(temp->args[i],">>"))
		{
			fd = open(temp->args[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0664);
			dup2(fd, OUT);
			temp->args = new_cmd_arg(temp->args);
			return ;
		}
		i++;
	}
}

void	execute_one(t_cmds  *cmds, t_env_vars *vars, int index, int *pidfd, int *store)
{
    int     pid;
    int     status;

    pid = fork();
    if (pid == 0)
    {
		case_pipe(index, pidfd, store, cmds);
		if(index == 0)
			case_redirect(index, pidfd, store[IN], cmds);
        if (isbuiltin(*cmds->args))
			execute_builtin(cmds->args, vars);
        else
			execute_builtout(cmds->args, vars);
        exit(errno);
    }
	close(pidfd[OUT]);
	if(index != 0)
		close(store[IN]);
	waitpid(pid, &status, 0);
	WEXITSTATUS(status);
    store[IN] = pidfd[IN];
}

void    for_each_command(t_cmds *cmds, t_env_vars *vars)
{
    t_cmds  *temp;
	int		index;
	int		pidfd[2];
	int		store[2];

	store[IN] = 0;
	index = 0;
    temp = cmds;
	if(!ft_strcmp(*cmds->args, "exit"))
		builtin_exit(cmds->args, vars);
    while (cmds != NULL)
    {
		pipe(pidfd);
		execute_one(cmds, vars, index, pidfd, store);
		cmds = cmds->next;
		index++;
    }
	close(store[IN]);
    delete_cmds(&temp);

}

void	execute_commands(t_tokens *tokens, t_env_vars *vars)
{
    t_cmds  *cmds;

    if (tokens == NULL || tokens->label == PIPE)
    {
        delete_tokens(&tokens);
        return ;
    }
	cmds = list_to_args(tokens);
    for_each_command(cmds, vars);
    delete_tokens(&tokens);
}
