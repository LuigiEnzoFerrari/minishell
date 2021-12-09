#include <minishell.h>

int	isblink(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

// void	expasion(t_tokens *tokens)
// {

// }

void	lexical_analysis_and_parse(char *input)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	while (tokens)
	{
		ft_putnbr(tokens->label);
		ft_putstr("  ");
		ft_putendl_fd(tokens->token, 1);
		tokens = tokens->next;
	}
	// expasion(tokens);
	return ;
}
