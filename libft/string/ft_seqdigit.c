/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seqdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:26:58 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 14:59:55 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_seqdigit(char *str)
{
	size_t	i;

	while (*str && !(ft_isdigit(*str)))
		str++;
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}
