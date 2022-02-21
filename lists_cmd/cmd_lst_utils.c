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

void	array_print(char **sla)
{
	size_t	i;

	i = 0;
	while (sla[i] != NULL)
	{
		ft_putendl_fd(sla[i], 1);
		i++;
	}
}

t_cmds	*pipe_commands(t_tokens *tokens)
{
	char	**args;
	int		*labels;
	t_cmds	*cmds;
	size_t	i;
	size_t	size;

	i = 0;
	cmds = NULL;
	args = NULL;
	size = (count(tokens) + 1);
	args = malloc(sizeof(char *) * (size + 1));
	labels = malloc(sizeof(int) * (size + 1));
	while (tokens != NULL)
	{
		args[i] = ft_strdup(tokens->token);
		labels[i] = tokens->label;
		tokens = tokens->next;
		if (tokens == NULL || tokens->label == PIPE)
		{
			args[i + 1] = NULL;
			labels[i + 1] = 0;
			push_cmd(&cmds, args, labels);
			if (tokens != NULL)
			{
				while (tokens->next != NULL && tokens->next->label == PIPE)
					tokens = tokens->next;
				if (tokens->next != NULL)
				{
					args = malloc(sizeof(char *) * (count(tokens->next) + 1));
					labels = malloc(sizeof(int) * (count(tokens->next) + 1));
				}
				tokens = tokens->next;
			}
			i = 0;
		}
		else
			i++;
	}
	return (cmds);
}
