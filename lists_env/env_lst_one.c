#include <minishell.h>

t_environ	*init_env(char *key, char *value)
{
	t_environ	*new;

	new = malloc(sizeof(t_environ));
	if (new == NULL)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	delete_env(t_environ **envs)
{
	if (envs == NULL || *envs == NULL)
		return ;
	free((*envs)->key);
	free((*envs)->value);
	free(*envs);
	*envs = NULL;
}

t_environ	*last_env(t_environ *envs)
{
	if (envs != NULL)
		while (envs->next != NULL)
			envs = envs->next;
	return (envs);
}

void	push_env(t_environ **envs, char *key, char *value)
{
	t_environ	*new;

	new = init_env(key, value);
	if (envs != NULL && *envs != NULL)
		last_env(*envs)->next = new;
	else
		*envs = new;
}

void	delete_envs(t_environ **tokens)
{
	if (tokens != NULL && *tokens != NULL)
		delete_envs(&(*tokens)->next);
	delete_env(tokens);
}

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
