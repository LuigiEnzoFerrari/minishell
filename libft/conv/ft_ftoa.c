/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:41:37 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/06/08 17:09:06 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"

static long double	ft_round(long double n)
{
	long double		right;
	long unsigned	left;

	left = (unsigned)n;
	right = n - (double)left;
	if (right > 0.5)
		n += 0.5;
	else if (right == 0.5)
	{
		if ((left % 2))
			n += 0.5;
	}
	return ((unsigned long)n);
}

static char	*ft_left(char *str, size_t len, unsigned long right, long double n)
{
	str = ft_rejoin(str, ".");
	while (len--)
	{
		n *= 10;
		right = n;
		right %= 10;
		str = ft_joindel(str, ft_itoa(right));
	}
	return (str);
}

char	*ft_ftoa(long double n, size_t len)
{
	char			*str;
	unsigned long	left;
	unsigned long	right;

	right = 0;
	if (!len)
		n = ft_round(n);
	left = (long unsigned)n;
	n = n - (long double)left;
	str = ft_itoa(left);
	if (len)
		str = ft_left(str, len, right, n);
	return (str);
}
