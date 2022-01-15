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

t_environ	*get_envs_a(void)
{
	size_t		i;
	t_environ	*envs;

	i = 0;
	envs = NULL;
	while (__environ[i])
	{
		to_env_list(&envs, __environ[i]);
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
    t_vars      *vars;

    vars = malloc(sizeof(t_vars));
	vars->envs_a = get_envs_a();
    vars->envs_b = NULL;
	while (42)
	{
		input = get_input(vars->envs_a);
		if (input != NULL && *input != '\0')
			save_history(input);
		lexical_analysis_and_parse(input, vars);
        free(input);
		execution();
	}
	delete_envs(&vars->envs_a);
	delete_envs(&vars->envs_b);
    free(vars);
 	return (0);
}

int	main(int argc, char **argv)
{
	if (shell_init())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
