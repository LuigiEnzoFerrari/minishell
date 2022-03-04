/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:19:47 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:19:48 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	last_returns(int n, char **save, char **line)
{
	char	*temp;

	if (n < 0)
		return (-1);
	*line = ft_substr(*save, 0, ft_strclen(*save, '\n'));
	if (!line)
		return (-1);
	if (ft_strchr(*save, '\n'))
	{
		temp = ft_strdup(ft_strchr(*save, '\n') + 1);
		free(*save);
		*save = temp;
		return (1);
	}
	free(*save);
	*save = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[RLIMIT_NOFILE];
	char		*buffer;
	int			nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	if (!save[fd])
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buffer[nbytes] = '\0';
		save[fd] = ft_rejoin(save[fd], buffer);
		if (ft_strchr(save[fd], '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (last_returns(nbytes, &save[fd], line));
}
