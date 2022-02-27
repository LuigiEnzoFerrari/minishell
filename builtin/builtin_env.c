/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:41:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:41:52 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	builtin_env(char **args, t_environ *envs)
{
	while (envs != NULL )
	{
		printf("%s=%s\n", envs->key, envs->value);
		envs = envs->next;
	}
}
