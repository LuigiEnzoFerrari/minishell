/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:06:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/06 22:36:33 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	sub_len;
	size_t	i;

	i = 0;
	sub_len = ft_strlen(substr);
	if (!sub_len)
		return ((char *)str);
	while (str[i] && sub_len <= len)
	{
		if (ft_strncmp(&str[i], substr, sub_len) == 0)
			return ((char *)&str[i]);
		i++;
		len--;
	}
	return (NULL);
}
