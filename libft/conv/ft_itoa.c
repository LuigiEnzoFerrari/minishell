/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:33 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 17:16:57 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_nbrlen(n) + 1;
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_nbrcpy(str, n);
	return (str);
}
