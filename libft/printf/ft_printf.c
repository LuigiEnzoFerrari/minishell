/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 03:54:27 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/15 04:41:49 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *form, ...)
{
	size_t	i;
	va_list	ap;
	t_tool	tool;

	i = 0;
	tool.len = 0;
	va_start(ap, form);
	while (form[i])
	{
		ft_putchar(form[i]);
		i++;
	}
	va_end(ap);
	return (i);
}
