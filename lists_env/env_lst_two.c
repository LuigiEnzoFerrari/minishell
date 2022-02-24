#include <minishell.h>

t_environ	*get_env(t_environ *envs, char *key)
{
	while (envs != NULL)
	{
		if (ft_strcmp(key, envs->key) == 0)
			return (envs);
		envs = envs->next;
	}
	return (NULL);
}

void	update_env(t_environ *envs, char *key, char *value)
{
	while (envs != NULL)
	{
		if (ft_strcmp(envs->key, key) == 0)
		{
			free(envs->value);
			envs->value = ft_strdup(value);
			return ;
		}
		envs = envs->next;
	}
}

char	*get_env_value(t_environ *envs, char *key)
{
	while (envs != NULL)
	{
		if (ft_strcmp(envs->key, key) == 0)
			break ;
		envs = envs->next;
	}
	if (envs == NULL)
		return (NULL);
	return (envs->value);
}
