/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 04:44:21 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/04/25 23:38:19 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			maxlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	maxlen = ft_strnlen(s, len);
	ptr = (char *)malloc(sizeof(char) * (maxlen + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, (s + start), maxlen);
	ptr[maxlen] = '\0';
	return (ptr);
}
