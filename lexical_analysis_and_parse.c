#include <minishell.h>

void	parses(char *input)
{
	char	**piped_tokens;
	char	***parsed_tokens;

	// piped_tokens = parse_pipes(input);
	// parsed_tokens = parse_tokens(piped_tokens);

	return ;
}

void	save_history(char *input)
{
	if (*input != '\0')
	{
		ft_putendl_fd(input, 1); // remove
		add_history(input);
		parses(NULL);
		return ;
	}
	free(input);
}

char *get_full_prompt(void)
{
	char	path[1000];
	char	*path_colored;

	getcwd(path, sizeof(path));
	path_colored = ft_strjoin(IGREEN, path);
	path_colored = ft_rejoin(path_colored, COLOR_OFF);
	path_colored = ft_rejoin(path_colored, "$ ");
	
	return path_colored;
}

int	isblink(int c)
{
	return (c == '\t' || c == '\r' ||
		c == '\n' || c == '\a' || c == ' ');
}


char	*get_input(void)
{
	char	*buff;
	char	*input;

	buff = get_full_prompt();
	input = readline(buff);
	buff = input;
	input = ft_skip_chr(input, isblink, 1);
	input = ft_strdup(input);
	free(buff);
	return (input);
}

size_t	token_len(char *str, int (*f)(int))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && !f(str[i]))
		i++;
	return (i);
}

void	tokenize(char *input)
{
	char	*str;

	str = "";
	while (*input != '\0')
	{
		if (*input == '|')
			;
		else if (*input == '"')
			;
		else if (*input == '\'')
			;
		else if (*input == '>')
			;
		else
			input++;
	}
}

void	lexical_analysis_and_parse(void)
{
	char	*input;

	input = get_input();
	if (input != NULL)
		save_history(input);
	tokenize(input);
	return ;
}
