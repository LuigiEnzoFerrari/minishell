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
        *args = ft_joindel(ft_strdup("/usr/bin/"), *args);
        execve(*args, args, __environ);
        perror(strerror(errno));
}

void	case_pipe(int index, int *pidfd, int storeIN, t_cmds  *temp)
{
	if(index == 0)
	{
		if(temp->next != NULL)
			dup2(pidfd[OUT], OUT);
	}
	else if(temp->next == NULL)
		dup2(storeIN, IN);
	else 
	{
		dup2(pidfd[OUT], OUT);
		dup2(storeIN, IN);
	}
}

void	case_redirect(int index, int *pidfd, int storeIN, t_cmds  *temp, t_cmds *cmds)
{
	return ;
}

int		execute_one(t_cmds *cmds, t_cmds  *temp, t_env_vars *vars, int index, int *pidfd, int storeIN)
{
    int     pid;
    int     status;

	if(!ft_strcmp(*temp->args, "exit"))
		builtin_exit(temp->args, vars);
    pid = fork();
    if (pid == 0)
    {
		case_pipe(index, pidfd, storeIN, temp);
		case_redirect(index, pidfd, storeIN, temp, cmds);
		if(temp->args)
        if (isbuiltin(*temp->args))
			execute_builtin(temp->args, vars);
        else
			execute_builtout(temp->args, vars);
        exit(errno);
    }
	close(pidfd[OUT]);
	if(index != 0)
		close(storeIN);
	waitpid(pid, &status, 0);
	WEXITSTATUS(status);
	return pidfd[0];
}

void    for_each_command(t_cmds *cmds, t_env_vars *vars)
{
    t_cmds  *temp;
	int		index;
	int		pidfd[2];
	int		storeIN;

	storeIN = 0;
	index = 0;
    temp = cmds;
    while (temp != NULL)
    {
		pipe(pidfd);
		storeIN = execute_one(cmds, temp, vars, index, pidfd, storeIN);
		temp = temp->next;
		index++;
    }
	close(storeIN);
    delete_cmds(&cmds);

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
