#include <minishell.h>

typedef struct sigaction	t_sigaction;

void	sighandler(int sig, siginfo_t *info, void *context)
{
	write(1, "lorem ipsum", 12);
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

void	lexical_analysis_and_parse(void)
{
	char	*buff;
	char	*input;

	buff = get_full_prompt();
	input = readline(buff);
	free(buff);
	if (*input != '\0')
		ft_putendl_fd(input, 1);
	return ;
}

void	expasion(void) {
	return ;
}

void execution(void) {
	return ;
}

int shell_init(void)
{
	char		*all;
	t_sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sighandler;
	if (sigemptyset(&act.sa_mask)
			|| sigaction(SIGTERM, &act, NULL))
			return (1);
	while (42)
	{
		lexical_analysis_and_parse();
		expasion();
		execution();
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (shell_init())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}