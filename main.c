#include <minishell.h>

t_environ	*get_envs_a(void)
{
	t_environ	*envs;
	size_t		i;

	envs = NULL;
	i = 0;
	while (__environ[i])
		to_env_list(&envs, __environ[i++]);
	return (envs);
}

t_env_vars	*get_environment_variables()
{
	t_env_vars	*vars;
	vars = malloc(sizeof(t_env_vars));
	vars->envs_a = get_envs_a();
	vars->envs_b = NULL;
	return vars;
}

void	shell_init(void)
{
	t_env_vars	*env_vars;
	t_tokens	*tokens;
	char		*input;

	env_vars = get_environment_variables();
	while (42)
	{
		input = get_input(env_vars->envs_a);
		tokens = lexical_analysis_and_parse(input, env_vars);
		execute_commands(tokens, env_vars);
	}
}

int	main(int argc, char **argv)
{
	shell_init();
	return(0);
}
