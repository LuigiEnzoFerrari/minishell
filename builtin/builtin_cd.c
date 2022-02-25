#include <minishell.h>

static char	*new_path(t_environ *envs, char *path)
{
	char	*new;

	if (envs != NULL)
	{
		new = get_env_value(envs, path);
		if (new != NULL)
			new = ft_strdup(get_env_value(envs, path));
	}
	else
		new = ft_strdup(path);
	return (new);
}

char	*tilde_sub(char *arg, t_environ *envs)
{
	char	*home;
	char	*new;

	home = get_env_value(envs, "HOME");
	if (home == NULL)
        return(ft_strdup("/"));
	new = malloc(sizeof(char) * (ft_strlen(home) + ft_strlen(arg)));
	ft_strcpy(new, home);
	ft_strcat(new, arg + 1);
	return (new);
}

void	builtin_cd(char **args, t_environ *envs)
{
	char	*path;

	if (*args != NULL && *(args + 1) != NULL)
	{
		ft_putendl_fd("bash: too many arguments", STDERR_FILENO);
		return ;
	}
	else if (*args == NULL)
    {
        if (get_env_value(envs, "HOME") != NULL)
            path = new_path(envs, "HOME");
        else
        {
            ft_putendl_fd("HOME not set", STDERR_FILENO);
            return ;
        }
    }
	else if (**args == '~')
		path = tilde_sub(*args, envs);
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
