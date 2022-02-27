/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_lst_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:01 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:39:02 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
