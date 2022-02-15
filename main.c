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
		rl_replace_line("",0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv)
{
	t_env_vars	*env_vars;
	t_tokens	*tokens;
	char		*input;

	env_vars = get_environment_variables();
	while (42)
	{
        //printf("this: %d: \n", *last_status_number());
		signal(SIGINT, handle_signals);
		signal(SIGQUIT, handle_signals);
		input = get_input(env_vars->global_vars, env_vars);
		tokens = lexical_analysis_and_parse(input, env_vars);
		execute_commands(tokens, env_vars);
	}
	return(0);
}
