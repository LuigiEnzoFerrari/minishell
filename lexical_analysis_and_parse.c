#include <minishell.h>



int	isblink(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

void	lexical_analysis_and_parse(char *input)
{
	t_tokens	*tokens;

	tokens = tokenize(input);

	return ;
}
