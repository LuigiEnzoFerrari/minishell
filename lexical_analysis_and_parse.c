#include <minishell.h>

int	ft_isblank(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

void	replace(t_tokens *tokens, int n)
{
	return ;
}

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
	if (value == NULL)
		value = ft_strndup("Not found", 8);
	new_token = ft_rejoin(new_token, value);
	new_token = ft_rejoin(new_token, &token[i + 1 + j]);
	return (new_token);
}

char	*get_new_token(char *tokens, size_t i, t_environ *envs)
{
	char	*new_token;

	if (tokens[i + 1] == '?')
	{
		new_token = ft_strndup(tokens, i);
		new_token = ft_rejoin(new_token, "HOLDER");
		new_token = ft_rejoin(new_token, tokens + i + 2);
	}
	else if (tokens[i + 1] == '$')
	{
		new_token = ft_strndup(tokens, i);
		new_token = ft_rejoin(new_token, " LOREM IPSULUM ");
		new_token = ft_rejoin(new_token, tokens + i + 2);
		ft_putstr("new_token : ");
		ft_putendl_fd(new_token, 1);
	}
	else if (tokens[i + 1] == '-')
	{
		new_token = ft_strndup(tokens, i);
		new_token = ft_rejoin(new_token, "himBHs");
		new_token = ft_rejoin(new_token, tokens + i + 2);
	}
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
	while (new_token[i] != '\0')
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

t_environ	*get_envs(void)
{
	size_t		i;
	t_environ	*envs;

	i = 0;
	envs = NULL;
	while (__environ[i])
	{
		env_duplicate(&envs, __environ[i]);
		i++;
	}
	return (envs);
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

void	lexical_analysis_and_parse(char *input)
{
	t_tokens	*tokens;
	t_environ	*envs;

	tokens = tokenize(input);
	envs = get_envs();
	// print_envs(envs);
	expasion(tokens, envs);
	while (tokens)
	{
		ft_putnbr(tokens->label);
		ft_putendl_fd(tokens->token, 1);
		tokens = tokens->next;
	}
	delete_envs(&envs);
	return ;
}
