#include <minishell.h>

void	builtin_pwd(char **args, t_environ *envs)
{
	char	*path;

	path = get_env_value(envs, "PWD");
    ft_putendl_fd(path, 1);
}
