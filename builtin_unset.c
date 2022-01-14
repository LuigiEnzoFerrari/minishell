#include <minishell.h>

void	builtin_unset(char **args, t_vars *vars)
{
    if (*args == NULL)
        return ;
    delete_env_by_key(&vars->envs_a, *args);
    delete_env_by_key(&vars->envs_b, *args); 
}
