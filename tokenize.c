#include <minishell.h>

void	add_pipe(t_tokens **tokens, char **input)
{
	push_token(tokens, "|", PIPE);
	(*input)++;
}

void	quote(t_tokens **tokens, char **input, int quote )
{
	char	*str;

	str = (*input);
	while (**input != quote && **input != '\0')
		(*input)++;
	if (**input == quote)
		(*input)++;
	str = ft_strndup(str, ft_strclen(str, quote));
	if (quote == '\'')
		push_token(tokens, str, SINGLE_QUOTE);
	else
		push_token(tokens, str, DOUBLE_QUOTE);
	free(str);
}


void	add_quotes(t_tokens **tokens, char **input)
{
	if (*(*input)++ == '\'')
		quote(tokens, input, '\'');
	else
		quote(tokens, input, '"');
}

void	add_redirections(t_tokens **tokens, char **input)
{
	(*input)++;
	if (**input == '>')
	{
		push_token(tokens, ">>", DOUBLE_REDIRECT);
		(*input)++;
	}
	else
		push_token(tokens, ">", SINGLE_REDIRECT);
}

void	add_string(t_tokens **tokens, char **input)
{
	char	*str;
	size_t	i;

	i = 0;
	while (!isblink((*input)[i]) && ((*input)[i]) != '\0')
		i++;
	str = ft_strndup(*input, i);
	while (!isblink((**input)) && (**input) != '\0')
		(*input)++;
	push_token(tokens, str, STRING);
	free(str);
}

t_tokens	*tokenize(char *input)
{
	t_tokens	*tokens;

	tokens = NULL;
	while (*input != '\0')
	{
		if (*input == '|')
			add_pipe(&tokens, &input);
		else if (*input == '>')
			add_redirections(&tokens, &input);
		else if (*input == '"' || *input == '\'')
			add_quotes(&tokens, &input);
		else
			add_string(&tokens, &input);
		input = ft_skip_chr(input, isblink, 1);
	}
	return (tokens);
}
