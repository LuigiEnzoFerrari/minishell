/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:42:05 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:42:06 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	builtin_unset(char **args, t_env_vars *vars)
{
	size_t	i;

	i = 0;
	if (*args == NULL)
		return ;
	while (args[i] != NULL)
	{
		delete_env_by_key(&vars->global_vars, args[i]);
		delete_env_by_key(&vars->local_vars, args[i]);
		i++;
	}
}
