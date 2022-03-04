/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:31:05 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/22 14:28:54 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	srclen;

	if (!src)
		return (0);
	srclen = ft_strlen(src);
	if (len == 0)
		return (srclen);
	if (srclen >= len)
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
		return (srclen);
	}
	ft_memcpy(dest, src, srclen);
	dest[srclen] = '\0';
	return (srclen);
}
