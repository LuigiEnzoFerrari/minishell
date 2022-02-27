/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtouts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:31 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:39:32 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	set_errno(int exit_status)
{
	if (exit_status == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (exit_status != ENOEXEC)
	{
		if (exit_status == ENOENT)
			return (EX_NOTFOUND);
		else if (exit_status != EPERM)
			return (EX_NOEXEC);
	}
	return (exit_status);
}

char	*to_environ(char *key, char *value)
{
	char	*environ;

	environ = ft_strjoin(key, "=");
	environ = ft_rejoin(environ, value);
	return (environ);
}

char	**t_environ_to_environ(t_environ *global_vars)
{
	char	**envs;
	size_t	size;

	size = size_envs(global_vars);
	envs = malloc(sizeof(char *) * (size + 1));
	envs[size] = NULL;
	while (global_vars != NULL)
	{
		size--;
		envs[size] = to_environ(global_vars->key, global_vars->value);
		global_vars = global_vars->next;
	}
	return (envs);
}

void	shell_execve(char *command, char **args, char **envs)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		execve(command, args, envs);
		perror(strerror(errno));
		exit(errno);
	}
	waitpid(pid, &status, 0);
	*last_status_number() = set_errno(WEXITSTATUS(status));
}

void	execute_builtout(char **args, t_env_vars *vars)
{
	char	**envs;
	char	*command;

	if (get_env_value(vars->global_vars, "PATH") == NULL)
		return ;
	envs = t_environ_to_environ(vars->global_vars);
	command = get_bin_path(*args, vars->global_vars);
	shell_execve(command, args, envs);
	free(command);
	ft_arrayfree(envs);
}
