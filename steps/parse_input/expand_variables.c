#include <minishell.h>

int token_ends(int c)
{
	if (c == ' ' || c == '\0' || c == '\''
		|| c == '\"' || c == '=' || c == '$')
		return (1);
	return (0);
}

char	*replace_variable(char *token, size_t i, t_env_vars *vars)
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
	value = get_env_value(vars->global_vars, env);
    if (value == NULL)
        value = get_env_value(vars->local_vars, env);
	if (value != NULL)
        new_token = ft_rejoin(new_token, value);
	new_token = ft_rejoin(new_token, &token[i + 1 + j]);
    free(env);
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

char	*get_new_token(char *tokens, size_t i, t_env_vars *vars)
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
        new_token = ft_strdup(tokens);
	else
		new_token = replace_variable(tokens, i, vars);
	return (new_token);
}

void	search_variables(t_tokens *tokens, char *token, t_env_vars *vars)
{
	size_t	i;
	char	*new_token;

	i = 0;
	new_token = token;
	while (new_token[0] != '\0' && new_token[i] != '\0')
	{
		if (new_token[i] == '$')
		{
			token = get_new_token(token, i, vars);
			if (new_token[i + 1] == '$')
				i++;
            free(new_token);
			new_token = token;
		}
		i++;
	}
	tokens->token = new_token;
}

void	expand_variables(t_tokens *tokens, t_env_vars *vars)
{
	while (tokens != NULL)
	{
		if (tokens->label == STRING || tokens->label == DOUBLE_QUOTE)
			search_variables(tokens, tokens->token, vars);
		tokens = tokens->next;
	}
}
