/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:44:26 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/06/08 18:17:00 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncat(char *dest, const char *src, size_t num)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (src_len < num)
		ft_strcpy(&dest[dest_len], src);
	else
	{
		ft_strncpy(&dest[dest_len], src, num);
		dest[dest_len + num] = '\0';
	}
	return (dest);
}
