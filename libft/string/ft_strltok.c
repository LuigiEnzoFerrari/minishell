/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 01:09:47 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/06 22:35:44 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strltok(const char *str, int c)
{
	size_t	i;
	size_t	strn;

	i = 0;
	strn = 0;
	while (str[i])
	{
		if (str[i] != c)
			strn++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (strn);
}
