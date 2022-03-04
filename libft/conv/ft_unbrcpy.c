/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:02:59 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 17:22:45 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"

char	*ft_unbrcpy(char *dest, unsigned int n)
{
	size_t	len;

	len = ft_unbrlen(n);
	dest[len] = '\0';
	while (len--)
	{
		dest[len] = ft_utochar(n);
		n /= 10;
	}
	return (dest);
}
