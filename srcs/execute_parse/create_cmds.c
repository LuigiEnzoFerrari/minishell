/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:21 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/03/01 19:27:16 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	number_of_tokens_on_command(t_tokens *tokens)
{
	size_t	i;

	i = 0;
	while (tokens != NULL && tokens->label != PIPE)
	{
		tokens = tokens->next;
		i++;
	}
	return (i);
}

static void	alloc_args_labels(
	char ***args,
	int **labels,
	size_t n)
{
	*args = malloc(sizeof(char *) * n);
	*labels = malloc(sizeof(int) * n);
}

static void	create_cmd(t_tokens **tokens, char **args, int *labels)
{
	t_tokens	*holder;
	size_t		i;

	i = 0;
	holder = (*tokens);
	while (holder != NULL && holder->label != PIPE)
	{
		args[i] = ft_strdup(holder->token);
		labels[i] = holder->label;
		i++;
		holder = holder->next;
	}
	args[i] = NULL;
	labels[i] = 0;
	while (holder != NULL && holder->label == PIPE)
		holder = holder->next;
	(*tokens) = holder;
}

t_cmds	*create_cmds(t_tokens *tokens)
{
	char	**args;
	int		*labels;
	t_cmds	*cmds;
	size_t	i;

	i = 0;
	cmds = NULL;
	while (tokens != NULL)
	{
		alloc_args_labels(&args, &labels,
			((number_of_tokens_on_command(tokens) + 1) + 1));
		create_cmd(&tokens, args, labels);
		push_cmd(&cmds, args, labels);
	}
	return (cmds);
}
