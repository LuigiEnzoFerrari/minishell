#include <minishell.h>

t_tokens	*add_new(char *token, int label)
{
	t_tokens	*new;

	new = malloc(sizeof(t_tokens));
	if (new == NULL)
		return (NULL);
	new->token = ft_strdup(token);
	new->label = label;
	new->next = NULL;
	return (new);
}

void	delete_token(t_tokens **token)
{
	if (token == NULL || *token == NULL)
		return ;
	free((*token)->token);
	free(*token);
	*token = NULL;
}

t_tokens	*last_token(t_tokens *tokens)
{
	if (tokens != NULL)
		while (tokens->next != NULL)
			tokens = tokens->next;
	return (tokens);
}

void    delete_top_token(t_tokens **tokens)
{
    t_tokens *temp;

    if (tokens == NULL || *tokens == NULL)
        return ;
    temp = (*tokens);
    (*tokens) = temp->next;
    delete_token(&temp);   
}


void	push_token(t_tokens **tokens, char *token, int label)
{
	t_tokens	*new;

	new = add_new(token, label);
	if (tokens != NULL && *tokens != NULL)
		last_token(*tokens)->next = new;
	else
		*tokens = new;
}

void	delete_tokens(t_tokens **tokens)
{
	if (tokens != NULL && *tokens !=  NULL)
		delete_tokens(&(*tokens)->next);
	delete_token(tokens);
}

size_t	number_of_labels(t_tokens *tokens, int label)
{
	size_t	n;

	n = 0;
	while (tokens != NULL)
	{
		if (tokens->label == label)
			n++;
		tokens = tokens->next;
	}
	return (n);
}
