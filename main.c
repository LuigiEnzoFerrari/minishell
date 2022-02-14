#include <minishell.h>

int *last_status_number()
{
    static  int lsn;

    return (&lsn);
}

int	main(int argc, char **argv)
{
	t_env_vars	*env_vars;
	t_tokens	*tokens;
	char		*input;

	env_vars = get_environment_variables();
	while (42)
	{
        printf("this: %d: \n", *last_status_number());
		input = get_input(env_vars->global_vars, env_vars);
		tokens = lexical_analysis_and_parse(input, env_vars);
		execute_commands(tokens, env_vars);
	}
	return(0);
}
