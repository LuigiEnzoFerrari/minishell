#include <minishell.h>

int	token_ends(int c)
{
	if (c == ' ' || c == '\0' || c == '\''
		|| c == '\"' || c == '=' || c == '$')
		return (1);
	return (0);
}

int	is_token(int c)
{
	if (c == '\'' || c == '"' || c == '>'
		|| c == '<' || c == '|')
		return (1);
	return (0);
}

int	ft_isblank(int c)
{
	return (c == '\t' || c == '\r'
		|| c == '\n' || c == '\a' || c == ' ');
}
