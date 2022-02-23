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

void	alloc_args_labels(t_tokens *tokens, char ***args, int **labels, size_t n)
{
	*args = malloc(sizeof(char *) * n);
	*labels = malloc(sizeof(int) * n);
}

void	create_cmd(t_tokens **tokens, char **args, int *labels)
{
	t_tokens *holder;
	size_t	i;

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

t_cmds	*pipe_commands(t_tokens *tokens)
{
	char	**args;
	int		*labels;
	t_cmds	*cmds;
	size_t	i;

	i = 0;
	cmds = NULL;
	while (tokens != NULL)
	{
		alloc_args_labels(tokens, &args, &labels, ((count(tokens) + 1) + 1));
		create_cmd(&tokens, args, labels);
		push_cmd(&cmds, args, labels);
	}
	return (cmds);
}
