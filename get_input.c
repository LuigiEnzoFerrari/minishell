#include <minishell.h>

char *get_full_prompt(t_environ *envs)
{
	// char		path[4096];
	char		*path_colored;
	char		*path;

	// change the getcwd function to ta $PWD variable

	// getcwd(path, sizeof(path));
	path = get_env_value(envs, "PWD");
	path_colored = ft_strjoin(IGREEN, path);
	path_colored = ft_rejoin(path_colored, COLOR_OFF);
	path_colored = ft_rejoin(path_colored, "$ ");
	
	return (path_colored);
}

char	*get_input(t_environ *envs)
{
	char	*buff;
	char	*input;

	buff = get_full_prompt(envs);
	input = readline(buff);
	buff = input;
	input = ft_skip_chr(input, ft_isblank, 1);
	input = ft_strdup(input);
	free(buff);
	return (input);
}
