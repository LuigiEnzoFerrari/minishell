/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_lst_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:38:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 22:54:02 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (tokens != NULL && *tokens != NULL)
		delete_tokens(&(*tokens)->next);
	delete_token(tokens);
}
