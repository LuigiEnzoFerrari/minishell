/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:26:51 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/09/29 12:51:57 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_array.h"

void	ft_arrayfree(char **array)
{
	char	**ptr;

	ptr = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(ptr);
}
