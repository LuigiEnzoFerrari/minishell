/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:40:31 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:40:32 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	has_key(t_environ *envs, char *key)
{
	while (envs != NULL)
	{
		if (ft_strcmp(key, envs->key) == 0)
			return (1);
		envs = envs->next;
	}
	return (0);
}

size_t	size_envs(t_environ *envs)
{
	size_t	i;

	i = 0;
	while (envs != NULL)
	{
		envs = envs->next;
		i++;
	}
	return (i);
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
