/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipctype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:27:50 by lenzo-pe          #+#    #+#             */
/*   Updated: 2022/02/27 15:27:51 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_skip_c_type(char *str, int (f)(int), int a)
{
	if (a)
		while (f(*str))
			str++;
	else
		while (!f(*str))
			str++;
	return (str);
}
