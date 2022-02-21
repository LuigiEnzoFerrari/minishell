#include <minishell.h>

void	case_pipe(int *save, t_cmds *cmds, int *stdpipe)
{
	if (cmds->index == 0)
	{
		if (cmds->next != NULL)
			dup2(cmds->pipe1[OUT], OUT);
	}
	else if (cmds->next == NULL)
	{
		dup2(save[IN], IN);
		dup2(stdpipe[OUT], OUT);
	}
	else
	{
		dup2(cmds->pipe1[OUT], OUT);
		dup2(save[IN], IN);
	}
}

void	save_pipes(int *stdpipe)
{
	stdpipe[IN] = dup(IN);
	stdpipe[OUT] = dup(OUT);
}

void	ajust_pipes(t_cmds *cmds, int *stdpipe, int *save)
{
	close(cmds->pipe1[OUT]);
	if (cmds->index != 0)
		close(save[IN]);
	save[IN] = cmds->pipe1[IN];
	if (cmds->next == NULL)
	{
		dup2(stdpipe[OUT], OUT);
		dup2(stdpipe[IN], IN);
		close(stdpipe[IN]);
	}
}
