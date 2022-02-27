/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:38:43 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 22:54:02 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	if_is_the_first_delelete(t_environ **envs, char *key)
{
	t_environ	*temp;

	temp = (*envs);
	if (ft_strcmp(temp->key, key) == 0)
	{
		(*envs) = (*envs)->next;
		delete_env(&temp);
		return (1);
	}
	return (0);
}

void	delete_env_by_key(t_environ **envs, char *key)
{
	t_environ	*temp;
	t_environ	*prev;

	if (envs == NULL || *envs == NULL)
		return ;
	temp = (*envs);
	if (if_is_the_first_delelete(envs, key))
		return ;
	while (42)
	{
		prev = temp;
		temp = temp->next;
		if (ft_strcmp(temp->key, key) == 0)
		{
			prev->next = temp->next;
			delete_env(&temp);
			return ;
		}
		if (temp->next == NULL)
			break ;
	}
}
