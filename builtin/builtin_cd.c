# include <minishell.h>

static char	*new_path(t_environ *envs, char *path)
{
	char	*new;

	if (envs != NULL)
		new = ft_strdup(get_env_value(envs, path));
	else
		new = ft_strdup(path);
    return (new);
}

// bash: cd: in: No such file or directory  
void	builtin_cd(char **args, t_environ *envs)
{
	char	*path;

    if (*args != NULL && *(args + 1) != NULL)
    {
        ft_putendl_fd("bash: too many arguments", STDERR_FILENO);
        return ;
    }
	else if (*args == NULL || ft_strcmp(*args, "~") == 0)
		path = new_path(envs, "HOME");
	else if (ft_strcmp(*args, "-") == 0)
		path = new_path(envs, "OLDPWD");
	else
		path = new_path(NULL, *args);
    if (chdir(path) != 0)
		perror(strerror(errno));
	else
    {
        free(path);
		path = getcwd(NULL, 0);
		update_env(envs, "OLDPWD", get_env_value(envs, "PWD"));
		update_env(envs, "PWD", path);
	}
    free(path);
}
