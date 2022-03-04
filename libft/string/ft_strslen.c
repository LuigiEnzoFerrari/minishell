/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:50:53 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 15:00:24 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	ft_strncmp_temp(const char *str1, const char *str2, size_t num)
{
	unsigned int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && --num)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

size_t	ft_strslen(const char *str, const char *substr)
{
	size_t	sub_len;
	size_t	i;

	i = 0;
	sub_len = ft_strlen(substr);
	while (str[i])
	{
		if (!(ft_strncmp_temp(&str[i], substr, sub_len)))
			return (i);
		i++;
	}
	return (i);
}
