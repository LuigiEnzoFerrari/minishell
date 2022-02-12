# include <minishell.h>

static int     check_redirects(t_tokens *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->label == SINGLE_REDIRECT || tokens->label == DOUBLE_REDIRECT
            ||  tokens->label == SINGLE_REDIRECT_IN)
			if (tokens->next == NULL || tokens->next->label == PIPE)
				return (1);
		tokens = tokens->next;
	}
	return (0);
}

int     check_syntax(t_tokens *tokens)
{
	if (tokens == NULL || tokens->label == PIPE)
		return (1);
	else if (check_redirects(tokens))
	{
		ft_putendl_fd("syntax error near unexpected token `|'", 1);
		return (1); 
	}
	return (0);
}

