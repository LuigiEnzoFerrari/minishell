/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:09 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 14:56:32 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	if (num == 0)
		return (0);
	while (str1[i] == str2[i] && --num)
		i++;
	return (str1[i] - str2[i]);
}
