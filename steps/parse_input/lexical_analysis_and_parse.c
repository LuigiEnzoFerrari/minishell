#include <minishell.h>

void    print_list(t_environ *envs)
{
    while (envs != NULL)
    {
        ft_putstr(envs->key);
        ft_putendl_fd(envs->value, 1);
        envs = envs->next;
    }
}

t_tokens	*lexical_analysis_and_parse(char *input, t_env_vars *vars)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	expand_variables(tokens, vars);
    init_local_vars(vars, &tokens);
    free(input);
    return (tokens);
}
