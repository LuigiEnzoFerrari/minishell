/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:41:59 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 22:54:02 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_keys(t_environ *envs)
{
	char	**keys;
	size_t	size;
	size_t	i;

	i = 0;
	size = size_envs(envs);
	keys = malloc(sizeof(char *) * (size + 1));
	while (envs != NULL)
	{
		keys[i] = ft_strdup(envs->key);
		envs = envs->next;
		i++;
	}
	keys[i] = NULL;
	return (keys);
}

char	**get_ordered_keys(t_environ *envs)
{
	char	**keys;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	keys = get_keys(envs);
	while (keys[i] != NULL)
	{
		j = 0;
		while (keys[j] != NULL)
		{
			if (strcmp(keys[i], keys[j]) < 0)
			{
				tmp = keys[i];
				keys[i] = keys[j];
				keys[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (keys);
}

void	print_exports(t_environ *envs)
{
	char	**keys;
	size_t	i;

	i = 0;
	keys = get_ordered_keys(envs);
	while (keys[i] != NULL)
	{
		ft_putstr("declare -x ");
		ft_putstr(keys[i]);
		ft_putstr("=");
		ft_putendl_fd(get_env_value(envs, keys[i]), 1);
		i++;
	}
	ft_arrayfree(keys);
}

void	add_exports(char **args, t_env_vars *vars)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strchr(args[i], '=') != NULL)
		{
			to_env_list(&vars->global_vars, args[i]);
			to_env_list(&vars->local_vars, args[i]);
		}
		i++;
	}
}

void	builtin_export(char **args, t_env_vars *vars)
{
	if (*args == NULL)
		print_exports(vars->global_vars);
	else
		add_exports(args, vars);
}
