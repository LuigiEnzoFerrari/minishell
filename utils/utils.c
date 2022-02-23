#include <minishell.h>

int	ft_isblank(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

int	has_key(t_environ *envs, char *key)
{
	while (envs != NULL)
	{
		if (ft_strcmp(key, envs->key) == 0)
			return (1);
		envs = envs->next;
	}
	return (0);
}

size_t	size_envs(t_environ *envs)
{
	size_t	i;

	i = 0;
	while (envs != NULL)
	{
		envs = envs->next;
		i++;
	}
	return (i);
}
