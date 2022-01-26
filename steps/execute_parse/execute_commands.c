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

void    execute_builtout(char **args, t_env_vars *vars)
{
    __pid_t pid;
    int     status;

    pid = fork();
    if (pid == 0)
    {
        *args = ft_joindel(ft_strdup("/usr/bin/"), *args);
        execve(*args, args, __environ);
        perror(strerror(errno));
        exit(errno);
    }
	waitpid(pid, &status, 0);
	WEXITSTATUS(status);
}

void    arrays_prints(char **args)
{
    size_t  i;

    i = 0;
    while (args[i])
    {
        ft_putstr(args[i]);
        ft_putstr(" ");
        i++;
    }
    ft_putstr("\n");
}

void    print_commands(t_cmds *cmds)
{
    while (cmds != NULL)
    {
        arrays_prints(cmds->args);
        cmds = cmds->next;
    }
}

void    execute_one(t_cmds *cmds, char **args, t_env_vars *vars)
{


    if (isbuiltin(*args))
        execute_builtin(args, vars);
    else
        execute_builtout(args, vars);
}


void    for_each_command(t_cmds *cmds, t_env_vars *vars)
{
    t_cmds  *temp;


    temp = cmds;
    while (temp != NULL)
    {
        execute_one(cmds, temp->args, vars);
        temp = temp->next;
    }
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
    // print_commands(cmds);
    for_each_command(cmds, vars);
    delete_tokens(&tokens);
}
