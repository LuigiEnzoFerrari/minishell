#include <minishell.h>

int	isblink(int c)
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

char	*replace_variable(char *token, size_t i)
{
	char	*new_token;
	size_t	j;

	j = 0;
	while (token_ends(token[i + 1 + j]) == 0)
		j++;
	new_token = ft_strndup(token, i);
	new_token = ft_rejoin(new_token, "HOLDER TO ENV");
	new_token = ft_rejoin(new_token, &token[i + 1 + j]);
	return (new_token);
}

char	*get_new_token(char *tokens, size_t i)
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
		new_token = ft_rejoin(new_token, "LOREM IPSULUM");
		new_token = ft_rejoin(new_token, tokens + i + 2);
	}
	else if (tokens[i + 1] == '-')
	{
		new_token = ft_strndup(tokens, i);
		new_token = ft_rejoin(new_token, "himBHs");
		new_token = ft_rejoin(new_token, tokens + i + 2);
	}
	else if (isblink(tokens[i + 1]) || tokens[i + 1] == ' '
		|| tokens[i + 1] == '=' || tokens[i + 1] == '#'
		|| tokens[i + 1] == '&' || tokens[i + 1] == '^'
		|| tokens[i + 1] == '%')
		return (tokens);
	else
		new_token = replace_variable(tokens, i);
	return (new_token);
}

void	search_variables(t_tokens *tokens, char *token)
{
	size_t	i;

	i = 0;
	while (token[i] != '\0')
	{
		if (token[i] == '$')
		{
			// free(tokens->token);
			tokens->token = get_new_token(token, i);
			if (token[i + 1] == '$')
				i++;
		}
		i++;
	}
}

void	expasion(t_tokens *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->label == STRING || tokens->label == DOUBLE_QUOTE)
			 search_variables(tokens, tokens->token);
		tokens = tokens->next;
	}
}

void	lexical_analysis_and_parse(char *input)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	expasion(tokens);
	while (tokens)
	{
		ft_putendl_fd(tokens->token, 1);
		tokens = tokens->next;
	}
	return ;
}
