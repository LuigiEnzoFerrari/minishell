#include <minishell.h>


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

void	to_env_list(t_environ **envs, char *environ)
{
    t_environ   *to_update;
    t_environ   *to_put; 
    
    to_put = to_env(environ);
    to_update = get_env(*envs, to_put->key);
    if (to_update != NULL)
    {
        free(to_update->value);
        to_update->value = to_put->value;
        free(to_put->key);
        free(to_put);
    }
    else
    {
        push_env(envs, to_put->key, to_put->value);
        delete_env(&to_update);
    }
}

