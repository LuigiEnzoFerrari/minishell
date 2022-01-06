#include <minishell.h>

void	new_path(char **args, t_environ *envs, char *path)
{
	char	*new;

	if (envs != NULL)
		new = ft_strdup(get_env_value(envs, path));
	else
		new = ft_strdup(path);
	*args = new;
}

// bash: cd: in: No such file or directory  
void	cd(char **args, t_environ *envs)
{
	char	*path;

	if (*args == NULL || ft_strcmp(*args, "~") == 0)
		new_path(args, envs, "HOME");
	else if (ft_strcmp(*args, "-") == 0)
		new_path(args, envs, "OLDPWD");
	else
		new_path(args, NULL, *args);

    if (chdir(*args) != 0)
		perror(strerror(errno));
	else {
		path = getcwd(NULL, 0);
		update_env(envs, "OLDPWD", get_env_value(envs, "PWD"));
		update_env(envs, "PWD", path);
		free(path);
	}
}

void	pwd(char **args, t_environ *envs)
{
	char	*path;

	path = get_env_value(envs, "PWD");
    ft_putendl_fd(path, 1);
}

void	export(char **args)
{
	ft_putendl_fd("export", 1);
}

void	unset(char **args)
{
	ft_putendl_fd("unset", 1);
}

void	env(char **args, t_environ *envs)
{
	while (envs != NULL)
	{
		ft_putstr_fd(envs->key, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(envs->value, 1);
		envs = envs->next;
	}
}

void	exits(char **args)
{
	ft_putendl_fd("exit", 1);
}
