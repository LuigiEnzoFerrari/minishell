#include <minishell.h>

t_cmds	*init_cmd(char **args)
{
	t_cmds	*new;

	new = malloc(sizeof(t_cmds));
	if (new == NULL)
		return (NULL);
	new->args = args;
	new->next = NULL;
	return (new);
}

void	delete_cmd(t_cmds **cmd)
{
	if (cmd == NULL || *cmd == NULL)
		return ;
    ft_arrayfree((*cmd)->args);
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

void	push_cmd(t_cmds **cmds, char **args)
{
	t_cmds	*new;

	new = init_cmd(args);
	if (cmds != NULL && *cmds != NULL)
		last_cmd(*cmds)->next = new;
	else
		*cmds = new;
}

void	delete_cmds(t_cmds **tokens)
{
	if (tokens != NULL && *tokens !=  NULL)
		delete_cmds(&(*tokens)->next);
	delete_cmd(tokens);
}
