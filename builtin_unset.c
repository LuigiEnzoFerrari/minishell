#include <minishell.h>

void	builtin_unset(char **args, t_env_vars *vars)
{
    size_t  i;

    i = 0;
    if (*args == NULL)
        return ;
    while (args[i] != NULL)
    {
        delete_env_by_key(&vars->envs_a, args[i]);
        delete_env_by_key(&vars->envs_b, args[i]);
        i++; 
    }
}
