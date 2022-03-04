/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:26:48 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/09/29 12:51:55 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_array.h"

char	**ft_arraydup(char **array)
{
	size_t	len;
	char	**ptr;

	len = ft_arraylen(array);
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = NULL;
	while (len--)
		ptr[len] = ft_strdup(array[len]);
	return (ptr);
}
