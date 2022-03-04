/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:06:31 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/06/08 20:33:26 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strccpy(char *dest, const char *src, size_t c)
{
	size_t	maxlen;
	size_t	i;

	i = 0;
	maxlen = ft_strclen(src, c);
	while (i < maxlen)
	{
		dest[i] = src[i];
		i++;
	}
	dest[maxlen] = '\0';
	return (dest);
}
