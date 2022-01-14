#include <minishell.h>

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
