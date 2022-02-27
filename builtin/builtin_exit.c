#include <minishell.h>

int	is_a_number(char *arg)
{
	while (arg != NULL)
	{
		if (ft_isdigit(*arg) == 0)
			return (0);
		arg++;
	}
	return (1);
}

void	exit_minishell(char **args, t_env_vars *vars, int exit_value)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (args != NULL)
		ft_arrayfree(args);
	if (vars->global_vars != NULL)
		delete_envs(&vars->global_vars);
	if (vars->local_vars != NULL)
		delete_envs(&vars->local_vars);
	free(vars);
    *last_status_number() = exit_value;
	exit(exit_value);
}

void	builtin_exit(char **args, t_env_vars *vars)
{
	int	exit_value;

	exit_value = EXIT_SUCCESS;
	if (args == NULL)
		exit_minishell(args, vars, EXIT_SUCCESS);
	if (*(args + 1) != NULL)
	{
		if ((is_a_number(*args + 1) != 0))
		{
			ft_putendl_fd("numeric argument required", STDERR_FILENO);
			exit_minishell(args, vars, 2);
		}
		else if (*(args + 2) != NULL)
        {
			ft_putendl_fd("too many arguments", STDERR_FILENO);
            *last_status_number() = 1;
        }
		else
		{
			exit_value = ft_atoi(*(args + 1));
			exit_minishell(args, vars, exit_value);
		}
	}
	else
		exit_minishell(args, vars, exit_value);
}
