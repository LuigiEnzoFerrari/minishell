#include <minishell.h>

t_environ	*add_env(char *key, char *value)
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

// void    delete_top_env(t_environ **envs)
// {
//     t_environ *temp;

//     if (envs == NULL || *envs == NULL)
//         return ;
//     temp = (*envs);
//     (*envs) = temp->next;
//     delete_env(temp);        
// }

void    remove_env(t_environ **envs, char *key)
{
    t_environ *temp;
    t_environ *prev;

    if (envs == NULL || *envs == NULL)
	    return ;
    temp = (*envs);
    if(ft_strcmp(temp->key, key) == 0)
    {
        (*envs) = (*envs)->next;
        delete_env(&temp);
        return ;
    }
    while (42)
    {
        prev = temp;
        temp = temp->next;
        if (ft_strcmp(temp->key, key) == 0)
        {
            prev->next = temp->next;
            delete_env(&temp);
            return ;
        }
        if (temp->next == NULL)
            break ;
    }
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

	new = add_env(key, value);
	if (envs != NULL && *envs != NULL)
		last_env(*envs)->next = new;
	else
		*envs = new;
}

void	delete_envs(t_environ **tokens)
{
	if (tokens != NULL && *tokens !=  NULL)
		delete_envs(&(*tokens)->next);
	delete_env(tokens);
}


t_environ *to_env(char *environ)
{
	size_t	    len;
    t_environ   *env;

    if (environ == NULL || ft_strchr(environ, '=') == NULL)
        return NULL;
	len = ft_strclen(environ, '=');
    env = malloc(sizeof(t_environ));
	env->key = ft_strndup(environ, len);
	env->value = ft_strdup(&environ[len + 1]);
    return (env);
}

int has_key(t_environ *envs, char *key)
{

    while (envs != NULL)
    {
        if (ft_strcmp(key, envs->key) == 0)
            return (1);
        envs = envs->next;
    }
    return (0);
}

t_environ *get_env(t_environ *envs, char *key)
{
    while (envs != NULL)
    {
        if (ft_strcmp(key, envs->key) == 0)
            return (envs);
        envs = envs->next;
    }
    return (NULL);
}

void	env_duplicate(t_environ **envs, char *environ)
{
	size_t	    len;
    t_environ   *env;
    t_environ   *kkkk; 
    
    kkkk = to_env(environ);
    env = get_env(*envs, kkkk->key);
    if (env != NULL)
    {
        free(env->value);
        env->value = kkkk->value;
        free(kkkk->key);
        free(env);
    }
    else
    {
        push_env(envs, kkkk->key, kkkk->value);
        delete_env(&env);
    }
}


void	env_update(t_environ *envs, char *key, char *value)
{
	while (envs != NULL)
	{
		if (ft_strcmp(envs->key, key) == 0)
		{
			free(envs->value);
			envs->value = ft_strdup(value);
            ft_putendl_fd("passou ak: ", 1);
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

void	update_env(t_environ *envs, char *key, char *value)
{
	while (envs != NULL)
	{
		if (ft_strcmp(envs->key, key) == 0)
			break ;
		envs = envs->next;
	}
	free(envs->value);
	envs->value = ft_strdup(value);
}

size_t  size_envs(t_environ *envs)
{
    size_t  i;

    i = 0;
    while (envs != NULL)
    {
        envs = envs->next;
        i++;
    }
    return (i);
}
