/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:28:13 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/09/29 12:54:14 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_ARRAY_H
# define FT_PUT_ARRAY_H
# include "ft_string.h"
# include "ft_put.h"

void	ft_putarray_fd(char **array, int fd);
void	ft_putarray(char **array);
void	ft_putarraydelim_fd(char **array, int c, int fd);
void	ft_putarraydelim(char **array, int c);

#endif
