#include <minishell.h>

t_environ *get_envs_b(t_tokens **tokens)
{
    t_environ   *envs;
    t_tokens    *temp;

    envs = NULL;
    temp = (*tokens);
    while (temp != NULL)
    {
        if (temp->label == STRING && ft_strchr(temp->token, '=') != NULL)
        {
            to_env_list(&envs, temp->token);
            delete_top_token(tokens);
            temp = (*tokens);
            continue ;
        }
        else
        {
            delete_envs(&envs);
            break ;
        }
        temp = temp->next;
    }
    return (envs);
}

void    init_envs_b(t_environ **envs, t_tokens **tokens)
{
    t_environ *temp;

    temp = get_envs_b(tokens);
    while (temp != NULL)
    {
        if (has_key(*envs, temp->key))
            env_update(*envs, temp->key, temp->value);
        else
            push_env(envs, temp->key, temp->value);
        temp = temp->next;
    }
}
