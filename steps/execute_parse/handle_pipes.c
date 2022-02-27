/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:43 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:39:44 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	case_pipe(int fds[3][2], t_cmds *cmds)
{
	if (cmds->index == 0)
	{
		if (cmds->next != NULL)
			dup2(fds[PIP][OUT], OUT);
	}
	else if (cmds->next == NULL)
	{
		dup2(fds[LAST][IN], IN);
		dup2(fds[STD][OUT], OUT);
	}
	else
	{
		dup2(fds[PIP][OUT], OUT);
		dup2(fds[LAST][IN], IN);
	}
}

void	save_pipes(int *fds_std)
{
	fds_std[IN] = dup(IN);
	fds_std[OUT] = dup(OUT);
}

void	ajust_pipes(t_cmds *cmds, int fds[3][2])
{
	close(fds[PIP][OUT]);
	if (cmds->index != 0)
		close(fds[LAST][IN]);
	fds[LAST][IN] = fds[PIP][IN];
	if (cmds->next == NULL)
	{
		dup2(fds[STD][OUT], OUT);
		dup2(fds[STD][IN], IN);
		close(fds[LAST][IN]);
		close(fds[STD][OUT]);
		close(fds[STD][IN]);
	}
}
