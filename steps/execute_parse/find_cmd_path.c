/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:39:39 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:39:40 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
