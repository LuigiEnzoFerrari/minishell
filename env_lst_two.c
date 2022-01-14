#include <minishell.h>

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

void    delete_env_by_key(t_environ **envs, char *key)
{
    t_environ   *temp;
    t_environ   *prev;

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