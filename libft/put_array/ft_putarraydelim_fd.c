/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarraydelim_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:27:16 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/09/29 10:03:46 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put_array.h"

void	ft_putarraydelim_fd(char **array, int c, int fd)
{
	while (*array)
	{
		ft_putstr_fd(*array++, fd);
		ft_putchar_fd(c, fd);
	}
}
