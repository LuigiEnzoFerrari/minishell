#include <minishell.h>

t_cmds	*init_cmd(char **args, int *labels)
{
	t_cmds	*new;

	new = malloc(sizeof(t_cmds));
	if (new == NULL)
		return (NULL);
	new->args = args;
	new->labels = labels;
	new->next = NULL;
	return (new);
}

void	delete_cmd(t_cmds **cmd)
{
	if (cmd == NULL || *cmd == NULL)
		return ;
	if ((*cmd)->args != NULL)
		ft_arrayfree((*cmd)->args);
	free((*cmd)->labels);
	free(*cmd);
	*cmd = NULL;
}

t_cmds	*last_cmd(t_cmds *cmds)
{
	if (cmds != NULL)
		while (cmds->next != NULL)
			cmds = cmds->next;
	return (cmds);
}

void	push_cmd(t_cmds **cmds, char **args, int *labels)
{
	t_cmds	*new;

	new = init_cmd(args, labels);
	if (cmds != NULL && *cmds != NULL)
		last_cmd(*cmds)->next = new;
	else
		*cmds = new;
}

void	delete_cmds(t_cmds **cmds)
{
	if (cmds != NULL && *cmds != NULL)
		delete_cmds(&(*cmds)->next);
	delete_cmd(cmds);
}
