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
	execve(*args, args, __environ);
	perror(strerror(errno));
}

void	case_pipe(int index, int *save, t_cmds  *cmds)
{
	if(index == 0)
	{
		if(cmds->next != NULL)
			dup2(cmds->pipe1[OUT], OUT);
	}
	else if(cmds->next == NULL)
		dup2(save[IN], IN);
	else 
	{
		dup2(cmds->pipe1[OUT], OUT);
		dup2(save[IN], IN);
	}
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
			redirects(cmds->args[i + 1],  O_RDONLY | O_CREAT, IN);
		i++;
	}
	cmds->args = remove_redirects(cmds->args, cmds->labels);
    if (cmds->args[0] == NULL)
        exit(errno);
}

void	execute_one(t_cmds  *cmds, t_env_vars *vars, int index, int *save)
{
	int     pid;
	int     status;

	pid = fork();
	if (pid == 0)
	{
		case_pipe(index, save, cmds);
		if(has_redirect(cmds->labels))
			case_redirect(save[IN], cmds);
		if (isbuiltin(*cmds->args))
			execute_builtin(cmds->args, vars);
		else
			execute_builtout(cmds->args, vars);
		exit(errno);
	}
	close(cmds->pipe1[OUT]);
	if(index != 0)
		close(save[IN]);
	waitpid(pid, &status, 0);
	WEXITSTATUS(status);
	save[IN] = cmds->pipe1[IN];
}

void    for_each_pipe_command(t_cmds *cmds, t_env_vars *vars)
{
	t_cmds  *temp;
	int		index;
	int		save[2];

	save[IN] = 0;
	index = 0;
	temp = cmds; 
	if(!ft_strcmp(*cmds->args, "exit"))
		builtin_exit(cmds->args, vars); 
	while (cmds != NULL)
	{
		pipe(cmds->pipe1);
		execute_one(cmds, vars, index, save);
		cmds = cmds->next;
		index++;
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
    print_cmds(cmds);
	for_each_pipe_command(cmds, vars);
	delete_tokens(&tokens);
}
