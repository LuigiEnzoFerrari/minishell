#include <minishell.h>

void	tratar(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}

void	each_cmd(t_cmds *cmds, int fds[2][2], t_env_vars *vars)
{
	mysignal(SIGINT, tratar);
	case_pipe(fds, cmds);
	case_redirect(cmds);
	if (cmds->args == NULL)
		;
	else if (isbuiltin(*cmds->args))
		execute_builtin(cmds->args, fds, vars);
	else
		execute_builtout(cmds->args, vars);
	ajust_pipes(cmds, fds);
}

void	for_each_cmd(t_cmds *cmds, t_env_vars *vars)
{
	t_cmds	*temp;
	int		fds[3][2];
	int		index;

	temp = cmds;
	index = 0;
	fds[LAST][IN] = IN;
	save_pipes(fds[STD]);
	while (cmds != NULL)
	{
		cmds->index = index;
		pipe(fds[PIP]);
		each_cmd(cmds, fds, vars);
		index++;
		cmds = cmds->next;
	}
	delete_cmds(&temp);
}

void	execute_cmds(t_tokens *tokens, t_env_vars *vars)
{
	t_cmds	*cmds;

	*last_status_number() = 0;
	if (check_syntax(tokens))
	{
		delete_tokens(&tokens);
		return ;
	}
	cmds = create_cmds(tokens);
	for_each_cmd(cmds, vars);
	delete_tokens(&tokens);
}
