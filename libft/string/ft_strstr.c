/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:43:09 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/06 22:36:43 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	sub_len;
	size_t	i;

	i = 0;
	sub_len = ft_strlen(substr);
	if (!sub_len)
		return ((char *)str);
	while (str[i])
	{
		if (ft_strncmp(&str[i], substr, sub_len) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
