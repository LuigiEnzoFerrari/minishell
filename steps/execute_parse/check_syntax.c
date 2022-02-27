/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:16 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 22:54:02 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect(int c)
{
	return (c == SINGLE_REDIRECT || c == DOUBLE_REDIRECT
		|| c == SINGLE_REDIRECT_IN || c == HEREDOC);
}

static int	is_invalid_redirect(t_tokens *tokens)
{
	while (tokens != NULL)
	{
		if (is_redirect(tokens->label))
			if (tokens->next == NULL || tokens->next->label == PIPE
				|| is_redirect(tokens->next->label))
				return (1);
		tokens = tokens->next;
	}
	return (0);
}

int	open_to_see(char *args, int flag)
{
	int	fd;

	fd = open(args, flag, 0664);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	is_invalid_redirect_input(t_tokens *tokens)
{
	int		stop;

	stop = 0;
	while (tokens != NULL)
	{
		if (stop)
			return (1);
		if (tokens->label == SINGLE_REDIRECT_IN)
			stop = open_to_see(tokens->next->token, O_RDONLY);
		tokens = tokens->next;
	}
	return (0);
}

int	check_syntax(t_tokens *tokens)
{
	if (tokens == NULL)
		return (1);
	else if (is_invalid_redirect(tokens) || tokens->label == PIPE)
	{
		ft_putendl_fd("syntax error near unexpected token", STDERR_FILENO);
		*last_status_number() = 2;
		return (1);
	}
	else if (is_invalid_redirect_input(tokens))
	{
		perror(strerror(errno));
		*last_status_number() = 1;
		return (1);
	}
	return (0);
}
