/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 01:44:36 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 17:04:54 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

void	ft_putnstr(char *str, int c)
{
	size_t	i;

	i = ft_strclen(str, c);
	if (str)
		while (*str != '\0' && i--)
			ft_putchar(*str++);
}
