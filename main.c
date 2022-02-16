#include <minishell.h>

int *last_status_number()
{
    static	int lsn;
    return (&lsn);
}

void	handle_signals(int sig)
{
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int  mysignal(int sig, void (*handler)(int))
{
	t_sigaction act;


	act.sa_handler = handler;
	act.sa_flags = 0;
	if (sigemptyset(&act.sa_mask)
		|| sigaction(sig, &act, NULL))
		return (1);
  return (0);
}

int	main(int argc, char **argv)
{
	t_env_vars	*env_vars;
	t_tokens	*tokens;
	char		*input;

	env_vars = get_environment_variables();
	while (42)
	{
        mysignal(SIGINT, handle_signals);
		input = get_input(env_vars->global_vars, env_vars);
		tokens = lexical_analysis_and_parse(input, env_vars);
		execute_commands(tokens, env_vars);
	}
	return(0);
}
