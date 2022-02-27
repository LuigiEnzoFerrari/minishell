/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:42:02 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 20:00:23 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	builtin_pwd(t_environ *envs)
{
	char	*path;

	path = get_env_value(envs, "PWD");
	ft_putendl_fd(path, 1);
}
