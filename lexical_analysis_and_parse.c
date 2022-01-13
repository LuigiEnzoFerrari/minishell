#include <minishell.h>

void	lexical_analysis_and_parse(char *input, t_vars *vars)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	expand_variables(tokens, vars->envs_a);
    init_envs_b(&vars->envs_b, &tokens);
    if (tokens != NULL)
        exec(tokens, vars->envs_a);
}
