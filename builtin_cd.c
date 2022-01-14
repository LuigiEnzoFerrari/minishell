# include <minishell.h>

static void	new_path(char **args, t_environ *envs, char *path)
{
	char	*new;

	if (envs != NULL)
		new = ft_strdup(get_env_value(envs, path));
	else
		new = ft_strdup(path);
	*args = new;
}

// bash: cd: in: No such file or directory  
void	builtin_cd(char **args, t_environ *envs)
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
	else
    {
		path = getcwd(NULL, 0);
		update_env(envs, "OLDPWD", get_env_value(envs, "PWD"));
		update_env(envs, "PWD", path);
		free(path);
	}
}
