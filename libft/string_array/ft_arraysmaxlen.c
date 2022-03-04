/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysmaxlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:27:04 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/09/29 12:52:03 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_array.h"

size_t	ft_arraysmaxlen(char **array)
{
	size_t	len;
	size_t	maxlen;

	len = 0;
	while (*array)
	{
		maxlen = ft_strlen(*array);
		if (maxlen > len)
			len = maxlen;
		array++;
	}
	return (len);
}
