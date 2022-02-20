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
    *last_status_number() = errno;
}
