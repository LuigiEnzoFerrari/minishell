#include <minishell.h>

void	pwd(char **args, t_environ *envs)
{
	char	*path;

	path = get_env_value(envs, "PWD");
    ft_putendl_fd(path, 1);
}

void	unset(char **args, t_environ *envs_a, t_environ *envs_b)
{
    if (*args == NULL)
        return ;
    delete_env_by_key(&envs_a, *args);
    // delete_env_by_key(&envs_b, )
}

void	env(char **args, t_environ *envs)
{
	while (envs != NULL)
	{
		ft_putstr_fd(envs->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(envs->value, 1);
		envs = envs->next;
	}
}

void	exits(char **args)
{
	ft_putendl_fd("exit", 1);
}
