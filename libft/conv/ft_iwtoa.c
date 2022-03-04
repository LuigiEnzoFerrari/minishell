/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iwtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:49:34 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 17:22:20 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"

char	*ft_iwtoa(int n, size_t w)
{
	char	*str;
	char	*ptr;
	size_t	len;

	len = ft_nbrlen(n);
	if (n < 0)
		len++;
	if (w > len)
		w -= len;
	else
		w = 0;
	str = (char *)malloc(sizeof(char) * (len + w + 1));
	if (!str)
		return (NULL);
	ptr = str;
	if (n < 0)
		*str++ = '-';
	ft_memset(str, '0', w);
	n = ft_abs(n);
	ft_nbrcpy(str + w, n);
	str[len + w] = '\0';
	return (ptr);
}
