/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis_and_parse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:40:06 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:40:07 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_tokens	*lexical_analysis_and_parse(char *input, t_env_vars *vars)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	expand_variables(tokens, vars);
	init_local_vars(vars, &tokens);
	free(input);
	return (tokens);
}
