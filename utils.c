#include <minishell.h>

int	ft_isblank(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

int isseparator(int label)
{
    if (label == PIPE ||
        label == SINGLE_REDIRECT || label == DOUBLE_REDIRECT ||
        label == HEARDOC)
        return (1);
    return (0);
}
