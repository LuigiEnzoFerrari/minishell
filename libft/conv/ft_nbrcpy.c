/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:43:38 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/09 06:23:17 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"

char	*ft_nbrcpy(char *dest, int n)
{
	size_t	len;
	int		num;

	num = n;
	len = ft_nbrlen(n);
	if (n < 0)
		len++;
	dest[len] = '\0';
	while (len--)
	{
		dest[len] = ft_tochar(n);
		n /= 10;
	}
	if (num < 0)
		*dest = '-';
	return (dest);
}
