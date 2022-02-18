#include <minishell.h>

int	ft_isblank(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

void print_tokens(t_tokens	*temp)
{
	int i = 0;
	while(temp)
	{
		printf("[%d] token:%s  label:%d\n", i, temp->token, temp->label);
		temp = temp->next;
		i++;
	}
}

void print_cmds(t_cmds	*temp)
{
	int i = 0;
	int j = 0;
	while(temp)
	{
		while(temp->args[j])
		{
			printf("[%d][%d] token:%s label:%d\n", i, j, temp->args[j], temp->labels[j]);
			j++;
		}
		j = 0;
		temp = temp->next;
		i++;
	}
}

void	print_array(char **paths)
{
	while(*paths)
		printf("[%s]\n", *paths++);
}