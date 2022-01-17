#include <minishell.h>


size_t	count(t_tokens *tokens)
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

void    array_print(char **sla)
{
    size_t  i;

    i = 0;
    while (sla[i] != NULL)
    {
        ft_putendl_fd(sla[i], 1);
        i++;
    }
}


t_cmds  *list_to_args(t_tokens *tokens)
{
	char    **args;
    t_cmds  *cmds;
	size_t  i, size;

	i = 0;
    cmds = NULL;
    size = (count(tokens) + 1);
	args = malloc(sizeof(char *) * (size + 1));
	while (tokens != NULL)
	{
		args[i] = ft_strdup(tokens->token);
        if (tokens->label == PIPE)
        {
            args[i + 1] = NULL;
            push_cmd(&cmds, args);
	        args = malloc(sizeof(char *) * (count(tokens->next) + 1));
	        i = 0;
        }
        else
            i++;
        tokens = tokens->next;
    
	}
	args[i] = NULL;
    push_cmd(&cmds, args);
	return (cmds);
}
