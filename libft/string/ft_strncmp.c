/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:30:54 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 15:00:51 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	if (!num)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && --num)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
