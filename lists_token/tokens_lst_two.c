#include <minishell.h>

void	delete_top_token(t_tokens **tokens)
{
	t_tokens	*temp;

	if (tokens == NULL || *tokens == NULL)
		return ;
	temp = (*tokens);
	(*tokens) = temp->next;
	delete_token(&temp);
}
