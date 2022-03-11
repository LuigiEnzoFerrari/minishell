/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:40:21 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 19:24:07 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_history(char *input)
{
	if (input == NULL || *input == '\0')
		return ;
	add_history(input);
}

static char	*get_full_prompt(t_environ *envs)
{
	char	*path_colored;
	char	*path;

	path = get_env_value(envs, "PWD");
	path_colored = ft_strjoin(IGREEN, path);
	path_colored = ft_rejoin(path_colored, COLOR_OFF);
	path_colored = ft_rejoin(path_colored, "$ ");
	return (path_colored);
}

char	*get_input(t_environ *envs, t_env_vars *vars)
{
	char	*old_input_address;
	char	*prompt;
	char	*input;

	prompt = get_full_prompt(envs);
	input = readline(prompt);
	if (input == NULL)
		builtin_exit(NULL, NULL, vars);
	old_input_address = input;
	input = ft_skip_c_type(input, ft_isblank, 1);
	input = ft_strdup(input);
	save_history(input);
	free(old_input_address);
	free(prompt);
	return (input);
}
