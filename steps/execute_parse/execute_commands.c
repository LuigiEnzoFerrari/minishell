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
    if (args == NULL)
        return ;
	else if (ft_strcmp(*args, "echo") == 0)
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
	if(args == NULL && !ft_strcmp(*args, ""))
		return ;
	*args = ft_joindel(ft_strdup("/usr/bin/"), *args);
    *last_status_number() = 66;
	execve(*args, args, __environ);
    // *last_status_number() = errno;
	perror(strerror(errno));
}


void tratar(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}
void	execute_one(t_cmds  *cmds, t_env_vars *vars, int *save)
{
	int     pid;
	int     status;

    status = 0;
	pid = fork();
	if (pid == 0)
	{
        case_pipe(save, cmds);
		if(has_redirect(cmds->labels))
			case_redirect(save[IN], cmds);
		if (isbuiltin(*cmds->args))
			execute_builtin(cmds->args, vars);
		else
			execute_builtout(cmds->args, vars);
		exit(errno);
	}
	close(cmds->pipe1[OUT]);
	if(cmds->index != 0)
		close(save[IN]);
	waitpid(pid, &status, 0);
    *last_status_number() =	WEXITSTATUS(status);
	save[IN] = cmds->pipe1[IN];
}

void    init_pipe(int *pipe1)
{
    pipe(pipe1);
}

void    for_each_pipe_command(t_cmds *cmds, t_env_vars *vars)
{
	t_cmds  *temp;
	int		save[2];

	save[IN] = IN;
	cmds->index = 0;
	temp = cmds; 
	while (cmds != NULL)
	{
        init_pipe(cmds->pipe1);
		execute_one(cmds, vars, save);
		cmds->index++;
		cmds = cmds->next;
	}
	close(save[IN]);
	delete_cmds(&temp);
}
    
void	execute_commands(t_tokens *tokens, t_env_vars *vars)
{
	t_cmds  *cmds;

	if (check_syntax(tokens))
	{
		delete_tokens(&tokens);
		return ;
	}
	cmds = pipe_commands(tokens);
	for_each_pipe_command(cmds, vars);
	delete_tokens(&tokens);
}
