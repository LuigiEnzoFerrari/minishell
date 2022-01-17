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

void    execute_builtin(char **args, t_vars *vars)
{
    if (ft_strcmp(*args, "echo") == 0)
        builtin_echo(args + 1);
	else if (ft_strcmp(*args, "cd") == 0)
		builtin_cd(args + 1, vars->envs_a);
	else if (ft_strcmp(*args, "pwd") == 0)
		builtin_pwd(args + 1, vars->envs_a);
	else if (ft_strcmp(*args, "export") == 0)
		builtin_export(args + 1, vars->envs_a);
	else if (ft_strcmp(*args, "unset") == 0)
		builtin_unset(args + 1, vars);
	else if (ft_strcmp(*args, "env") == 0)
		builtin_env(args, vars->envs_a);
	else
		builtin_exit(args, vars);
}

void    execute_builtout(char **args, t_vars *vars, int *io)
{
    __pid_t pid;
    int p[2], status;

    pid = 0;
    // if (pipe(p) < 0)
    //     exit(1);
    pid = fork();
    if (pid == 0)
    {

        *args = ft_strjoin("/usr/bin/", *args);
        execve(*args, args, __environ);
        perror(strerror(errno));
        exit(1);
    }
	waitpid(pid, &status, 0);
	WEXITSTATUS(status);
    // else
    // {
    //     *args = ft_strjoin("/usr/bin/", *args);
    //     execve(*args, args, __environ);
    // }

}


void	execute_commands(t_tokens *tokens, t_vars *vars)
{
    int     io[2];
    t_cmds  *cmds;
	// /usr/bin/ls
    if (tokens == NULL)
        return ;
	cmds = list_to_args(tokens);
    char **args = cmds->args;
    // array_print(args);
    delete_tokens(&tokens);
    if (isbuiltin(*args))
        execute_builtin(args, vars);
    else
        execute_builtout(args, vars, io);
    ft_arrayfree(args);
}
