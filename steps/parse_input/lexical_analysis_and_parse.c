#include <minishell.h>

t_tokens	*lexical_analysis_and_parse(char *input, t_env_vars *vars)
{
	t_tokens	*tokens;

	tokens = tokenize(input);
	expand_variables(tokens, vars);
    init_local_vars(vars, &tokens);
    free(input);
    return (tokens);
}
