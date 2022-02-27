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
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}

int	has_key(t_environ *envs, char *key)
{
	while (envs != NULL)
	{
		if (ft_strcmp(key, envs->key) == 0)
			return (1);
		envs = envs->next;
	}
	return (0);
}

size_t	size_envs(t_environ *envs)
{
	size_t	i;

	i = 0;
	while (envs != NULL)
	{
		envs = envs->next;
		i++;
	}
	return (i);
}

size_t	number_of_labels(t_tokens *tokens, int label)
{
	size_t	n;

	n = 0;
	while (tokens != NULL)
	{
		if (tokens->label == label)
			n++;
		tokens = tokens->next;
	}
	return (n);
}
