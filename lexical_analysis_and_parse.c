#include <minishell.h>


int token_ends(int c)
{
	if (c == ' ' || c == '\0' || c == '\''
		|| c == '\"' || c == '=' || c == '$')
		return (1);
	return (0);
}

char	*replace_variable(char *token, size_t i, t_environ *envs)
{
	char	*new_token;
	char	*env;
	size_t	j;
	char	*value;

	j = 0;
	while (token_ends(token[i + 1 + j]) == 0)
		j++;
	new_token = ft_strndup(token, i);
	env = ft_strndup(&token[i + 1], j);
	value = get_env_value(envs, env);
	if (value != NULL)
        new_token = ft_rejoin(new_token, value);
	new_token = ft_rejoin(new_token, &token[i + 1 + j]);
	return (new_token);
}

char	*make_new_token(char *tokens, char *trade, size_t i)
{
	char	*new_token;

	new_token = ft_strndup(tokens, i);
	new_token = ft_rejoin(new_token, trade);
	new_token = ft_rejoin(new_token, tokens + i + 2);
	return (new_token);
}

char	*get_new_token(char *tokens, size_t i, t_environ *envs)
{
	char	*new_token;

	if (tokens[i + 1] == '?')
		new_token = make_new_token(tokens, "> ? <", i);
	else if (tokens[i + 1] == '$')	
		new_token = make_new_token(tokens, "> $ <", i);
	else if (tokens[i + 1] == '\0')	
		new_token = make_new_token(tokens, "$", i);
	else if (tokens[i + 1] == '-')
		new_token = make_new_token(tokens, "himBHs", i);
	else if (ft_isblank(tokens[i + 1]) || tokens[i + 1] == ' '
		|| tokens[i + 1] == '=' || tokens[i + 1] == '#'
		|| tokens[i + 1] == '&' || tokens[i + 1] == '^'
		|| tokens[i + 1] == '%')
		return (tokens);
	else
		new_token = replace_variable(tokens, i, envs);
	return (new_token);
}

void	search_variables(t_tokens *tokens, char *token, t_environ *envs)
{
	size_t	i;
	char	*new_token;

	i = 0;
	new_token = token;
	while (new_token[0] != '\0' && new_token[i] != '\0')
	{
		if (new_token[i] == '$')
		{
			token = get_new_token(token, i, envs);
			if (new_token[i + 1] == '$')
				i++;
			new_token = token;
		}
		i++;
	}
	tokens->token = new_token;
}

void	expasion(t_tokens *tokens, t_environ *envs)
{
	while (tokens != NULL)
	{
		if (tokens->label == STRING || tokens->label == DOUBLE_QUOTE)
			 search_variables(tokens, tokens->token, envs);
		tokens = tokens->next;
	}
}


void	print_envs(t_environ *envs)
{
	while (envs != NULL)
	{
		ft_putstr(envs->key);
		ft_putstr(" || ");
		ft_putendl_fd(envs->value, 1);
		envs = envs->next;
	}
}

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
            env_duplicate(&envs, temp->token);
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

t_environ    *init_envs_b(t_environ **envs, t_tokens **tokens)
{
    t_environ *temp;

    temp = get_envs_b(tokens);
    while (temp != NULL)
    {
        if (has_key(*envs, temp->key))
        {
            update_env(*envs, temp->key, temp->value);

            ft_putendl_fd("ou nao?   ", 1);
        }
        else
        {
            push_env(envs, temp->key, temp->value);
            ft_putendl_fd("por que? ", 1);
        }
        temp = temp->next;
    }
    return (temp);
}

void printf_tokens(t_tokens *tokens)
{
    while (tokens)
    {
        printf("\nhere: %s\n", tokens->token);
        tokens = tokens->next;
    }
}

void	lexical_analysis_and_parse(char *input, t_vars *vars)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	// print_envs(envs);
	expasion(tokens, vars->envs_a);
    init_envs_b(&vars->envs_b, &tokens);
    print_envs(vars->envs_b);
    if (tokens != NULL)
        exec(tokens, vars->envs_a);
	return ;
}
