/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 20:13:37 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*replace_variable(char *token, size_t i, t_env_vars *vars)
{
	char	*new_token;
	char	*env;
	size_t	j;
	char	*value;

	j = 0;
	while (token_ends(token[i + 1 + j]) == 0)
		j++;
	new_token = ft_strndup(token, i);
	env = ft_strndup(&token[i + 1], j);
	value = get_env_value(vars->global_vars, env);
	if (value == NULL)
		value = get_env_value(vars->local_vars, env);
	if (value != NULL)
		new_token = ft_rejoin(new_token, value);
	new_token = ft_rejoin(new_token, &token[i + 1 + j]);
	free(env);
	return (new_token);
}

char	*make_new_token(char *tokens, char *trade, size_t i)
{
	char	*new_token;

	new_token = ft_strndup(tokens, i);
	new_token = ft_rejoin(new_token, trade);
	new_token = ft_rejoin(new_token, tokens + i + 2);
	return (new_token);
}

char	*get_new_token(char *tokens, size_t i, t_env_vars *vars)
{
	char	*new_token;
	char	*exit_number;

	exit_number = ft_itoa(*last_status_number());
	if (tokens[i + 1] == '?')
		new_token = make_new_token(tokens, exit_number, i);
	else if (tokens[i + 1] == '$')
		new_token = make_new_token(tokens, "42", i);
	else if (tokens[i + 1] == '\0')
		new_token = make_new_token(tokens, "$", i);
	else if (tokens[i + 1] == '-')
		new_token = make_new_token(tokens, "himBHs", i);
	else if (ft_isblank(tokens[i + 1]) || tokens[i + 1] == ' '
		|| tokens[i + 1] == '=' || tokens[i + 1] == '#'
		|| tokens[i + 1] == '&' || tokens[i + 1] == '^'
		|| tokens[i + 1] == '%')
		new_token = ft_strdup(tokens);
	else
		new_token = replace_variable(tokens, i, vars);
	free(exit_number);
	return (new_token);
}

void	search_variables(t_tokens *tokens, char *token, t_env_vars *vars)
{
	size_t	i;
	char	*new_token;

	i = 0;
	new_token = token;
	while (new_token[0] != '\0' && new_token[i] != '\0')
	{
		if (new_token[i] == '$' && new_token[i + 1] != '\0')
		{
			token = get_new_token(token, i, vars);
			if (new_token[i + 1] == '$')
				i++;
			free(new_token);
			new_token = token;
		}
		i++;
	}
	tokens->token = new_token;
}

void	expand_variables(t_tokens *tokens, t_env_vars *vars)
{
	while (tokens != NULL)
	{
		if (tokens->label == STRING || tokens->label == DOUBLE_QUOTE)
			search_variables(tokens, tokens->token, vars);
		tokens = tokens->next;
	}
}
