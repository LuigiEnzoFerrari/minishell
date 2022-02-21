#include <minishell.h>

int	set_errno(int exit_status)
{
	if (exit_status == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (exit_status != ENOEXEC)
	{
		if (exit_status == ENOENT)
			return (EX_NOTFOUND);
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

char	**parse_path(char *path)
{
	char	**bin_paths;

	bin_paths = ft_split(path, ':');
	return (bin_paths);
}

char	*find_path(char *arg, char **bin_paths)
{
	char		*path;
	struct stat	stats;

	while (*bin_paths)
	{
		path = ft_strjoin(*bin_paths, "/");
		path = ft_rejoin(path, arg);
		if (stat(path, &stats) == 0)
			return (path);
		free(path);
		bin_paths++;
	}
	return (ft_strdup(arg));
}

char	*get_bin_path(char *args, t_environ *envs)
{
	char	**paths;
	char	*env_path;
	char	*bin_path;

	env_path = get_env_value(envs, "PATH");
	paths = parse_path(env_path);
	if (paths != NULL)
	{
		bin_path = find_path(args, paths);
		ft_arrayfree(paths);
	}
	return (bin_path);
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

	envs = t_environ_to_environ(vars->global_vars);
	command = get_bin_path(*args, vars->global_vars);
	shell_execve(command, args, envs);
	free(command);
	ft_arrayfree(envs);
}
