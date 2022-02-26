#include <minishell.h>

void	builtin_env(char **args, t_environ *envs)
{
	while (envs != NULL )
	{
		printf("%s=%s\n", envs->key, envs->value);
		envs = envs->next;
	}
}