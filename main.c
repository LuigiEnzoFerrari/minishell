#include <minishell.h>


void	sighandler(int sig, siginfo_t *info, void *context)
{
	write(1, "lorem ipsum", 12);
}

void	expasion(void) {
	return ;
}

void execution(void) {
	return ;
}

int shell_init(void)
{
	// t_sigaction	act;

	// act.sa_flags = SA_SIGINFO;
	// act.sa_sigaction = sighandler;
	// if (sigemptyset(&act.sa_mask)
	// 		|| sigaction(SIGTERM, &act, NULL))
	// 		return (1);
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