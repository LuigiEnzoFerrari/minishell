# include <minishell.h>

int is_redirect(int c)
{
    return (c == SINGLE_REDIRECT || c == DOUBLE_REDIRECT
            ||  c == SINGLE_REDIRECT_IN ||  c == hereDOC);
}

static int     check_redirects(t_tokens *tokens)
{
	while (tokens != NULL)
	{
		if (is_redirect(tokens->label))
			if (tokens->next == NULL || tokens->next->label == PIPE
                || is_redirect(tokens->next->label))
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

