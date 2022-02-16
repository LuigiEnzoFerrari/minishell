#include <minishell.h>

void	case_pipe(int index, int *save, t_cmds  *cmds)
{
	if(index == 0)
	{
		if(cmds->next != NULL)
			dup2(cmds->pipe1[OUT], OUT);
	}
	else if(cmds->next == NULL)
		dup2(save[IN], IN);
	else 
	{
		dup2(cmds->pipe1[OUT], OUT);
		dup2(save[IN], IN);
	}
}

