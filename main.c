#include <minishell.h>


void	sighandler(int sig, siginfo_t *info, void *context)
{
	write(1, "lorem ipsum", 12);
}

// void	expasion(void) {
// 	return ;
// }

void execution(void) {
	return ;
}

void	save_history(char *input)
{
	if (*input != '\0')
	{
		// ft_putendl_fd(input, 1); // remove
		add_history(input);
		return ;
	}
	free(input);
}


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

t_environ	*get_envs(void)
{
	size_t		i;
	t_environ	*envs;

	i = 0;
	envs = NULL;
	while (__environ[i])
	{
		env_duplicate(&envs, __environ[i]);
		i++;
	}
	return (envs);
}

int shell_init(void)
{
	// t_sigaction	act;

	// act.sa_flags = SA_SIGINFO;
	// act.sa_sigaction = sighandler;
	// if (sigemptyset(&act.sa_mask)
	// 		|| sigaction(SIGTERM, &act, NULL))
	// 		return (1);
	char		*input;
	t_environ	*envs;

	envs = get_envs();
	while (42)
	{
		input = get_input(envs);
		if (input != NULL)
			save_history(input);
		lexical_analysis_and_parse(input, envs);
		execution();
	}
	delete_envs(&envs);
 	return (0);
}

int	main(int argc, char **argv)
{
	if (shell_init())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}