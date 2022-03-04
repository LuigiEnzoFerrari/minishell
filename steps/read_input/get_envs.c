/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:40:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 19:23:43 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_environ	*get_local_vars(t_tokens **tokens)
{
	t_environ	*envs;
	t_tokens	*temp;

	envs = NULL;
	temp = (*tokens);
	while (temp != NULL)
	{
		if (temp->label == STRING && ft_strchr(temp->token, '=') != NULL)
		{
			to_env_list(&envs, temp->token);
			delete_top_token(tokens);
			temp = (*tokens);
			continue ;
		}
		else
		{
			delete_envs(&envs);
			break ;
		}
		temp = temp->next;
	}
	return (envs);
}

void	init_local_vars(t_env_vars *vars, t_tokens **tokens)
{
	t_environ	*local_vars;
	t_environ	*temp;

	local_vars = get_local_vars(tokens);
	temp = local_vars;
	while (local_vars != NULL)
	{
		if (has_key(vars->global_vars, local_vars->key))
			update_env(vars->global_vars, local_vars->key, local_vars->value);
		if (has_key(vars->local_vars, local_vars->key))
			update_env(vars->local_vars, local_vars->key, local_vars->value);
		else
			push_env(&vars->local_vars, local_vars->key, local_vars->value);
		local_vars = local_vars->next;
	}
	delete_envs(&temp);
}

t_environ	*get_global_vars(void)
{
	t_environ	*envs;
	size_t		i;

	envs = NULL;
	i = 0;
	while (__environ[i])
	{
		if (ft_strnstr(__environ[i], "_WORKSPACE_",
				ft_strlen(__environ[i])) == NULL)
			to_env_list(&envs, __environ[i]);
		i++;
	}
	return (envs);
}

t_env_vars	*get_environment_variables(void)
{
	t_env_vars	*vars;

	vars = malloc(sizeof(t_env_vars));
	vars->global_vars = get_global_vars();
	vars->local_vars = NULL;
	return (vars);
}
