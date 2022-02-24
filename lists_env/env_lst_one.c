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
