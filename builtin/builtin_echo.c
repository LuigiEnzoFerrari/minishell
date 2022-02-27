/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:41:49 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 19:41:50 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	builtin_echo(char **args)
{
	size_t	i;
	int		option;

	i = 0;
	option = 0;
	if (*args == NULL)
		;
	else if (ft_strcmp(*args, "-n") == 0)
		option = 1;
	i += option;
	while (args[i] != NULL)
	{
		ft_putstr(args[i]);
		i++;
		if (args[i] != NULL)
			write(1, " ", 1);
	}
	if (option != 1)
		write(1, "\n", 1);
}
