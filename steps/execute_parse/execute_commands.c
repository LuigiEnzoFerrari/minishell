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
	*last_status_number() = errno;
}

int    set_errno(int exit_status)
{
    if (exit_status == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    else if (exit_status != ENOEXEC)
    {
        if (exit_status == ENOENT)
            return (EX_NOTFOUND);
        return (EX_NOEXEC);
    }
    return (exit_status);
}

void    execute_builtout(char **args, char **envs)
{
	int     pid;
	int     status;

    status = 0;
    pid = fork();
    if (pid == 0)
    {

        if(args == NULL && !ft_strcmp(*args, ""))
            return ;
        *args = ft_joindel(ft_strdup("/usr/bin/"), *args);
        execve(*args, args, envs);
        perror(strerror(errno));
        exit(errno);
    }
    waitpid(pid, &status, 0);
    *last_status_number() =	set_errno(WEXITSTATUS(status));
}

void tratar(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}

char *to_environ(char *key, char *value)
{
    char *environ;

    environ = ft_strjoin(key, "=");
    environ = ft_rejoin(environ, value);
    return (environ);
}

char    **t_environ_to_environ(t_environ *global_vars)
{
    char    **envs;
    size_t  size;

    size = size_envs(global_vars);
    envs = malloc(sizeof(char *) * (size + 1));
    envs[size] = NULL;
    while (global_vars != NULL)
    {
        size--;
        envs[size] = to_environ(global_vars->key, global_vars->value);
        global_vars = global_vars->next;
    }
    return (envs);
}

void	execute_one(t_cmds  *cmds, t_env_vars *vars, int *save, int *stdpipe)
{
    char    **envs;

    envs = t_environ_to_environ(vars->global_vars);
    mysignal(SIGINT, tratar);
    case_pipe(save, cmds, stdpipe);

    if(has_redirect(cmds->labels))
        case_redirect(save[IN], cmds);
    if (cmds->args[0] == NULL)
    {
        ajust_pipes(cmds, stdpipe, save);
        ft_arrayfree(envs);
        return ;
    }
    if (isbuiltin(*cmds->args))
        execute_builtin(cmds->args, vars); 
    else
        execute_builtout(cmds->args, envs);
    ajust_pipes(cmds, stdpipe, save);
    ft_arrayfree(envs);
}

void    for_each_pipe_command(t_cmds *cmds, t_env_vars *vars)
{
	t_cmds  *temp;
	int		save[2];
    int     stdpipe[2];
    int     index;

	temp = cmds; 
	save[IN] = IN;
	index = 0;
    save_pipes(stdpipe);
	while (cmds != NULL)
	{
        cmds->index = index;
        pipe(cmds->pipe1);
		execute_one(cmds, vars, save, stdpipe);
		index++;
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
