#include <minishell.h>

void	add_pipe(t_tokens **tokens, char **input)
{
	push_token(tokens, "|", PIPE);
	(*input)++;
}

void	add_quotes(t_tokens **tokens, char **input)
{
	char	*token;
	int		quote;
	size_t	len;

	quote = **input;
	if (ft_strchr((*input) + 1, quote) != NULL)
	{
		(*input)++;
		len = ft_strclen((*input), quote);
		token = ft_strndup((*input), len);
		if (quote == '\'')
			push_token(tokens, token, SINGLE_QUOTE);
		else
			push_token(tokens, token, DOUBLE_QUOTE);
		(*input) += (len + 1);
	}
	else
	{
		token = ft_strdup((*input));
		push_token(tokens, token, STRING);
		(*input) += ft_strlen(token);
	}
	free(token);
}

void	add_redirections(t_tokens **tokens, char **input)
{
	if (**input == '>')
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
    else
    {
	    (*input)++;
	    if (**input == '<')
	    {
	    	push_token(tokens, "<<", hereDOC);
	    	(*input)++;
        }
    	else
    		push_token(tokens, "<", SINGLE_REDIRECT_IN);
    }
}

void	add_string(t_tokens **tokens, char **input)
{
	char	*str;
	size_t	i;

	i = 0;
	while (!ft_isblank((*input)[i]) && ((*input)[i]) != '\0')
		i++;
	str = ft_strndup(*input, i);
	while (!ft_isblank((**input)) && (**input) != '\0')
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
		else if (*input == '>' || * input == '<')
			add_redirections(&tokens, &input);
		else if (*input == '"' || *input == '\'')
			add_quotes(&tokens, &input);
		else
			add_string(&tokens, &input);
		input = ft_skip_c_type(input, ft_isblank, 1);
	}
	return (tokens);
}
