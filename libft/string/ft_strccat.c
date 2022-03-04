/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:21:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:21:58 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strccat(char *dest, char *src, int c)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	num;

	num = ft_strclen(src, c);
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
