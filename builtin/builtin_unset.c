#include <minishell.h>

void	builtin_unset(char **args, t_env_vars *vars)
{
    size_t  i;

    i = 0;
    if (*args == NULL)
        return ;
    while (args[i] != NULL)
    {
        delete_env_by_key(&vars->global_vars, args[i]);
        delete_env_by_key(&vars->local_vars, args[i]);
        i++; 
    }
}
