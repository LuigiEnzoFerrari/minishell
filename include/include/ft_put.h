/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:35:40 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/06/06 09:56:57 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H
# include <unistd.h>
# include "ft_string.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);

void	ft_putchar(char c);
void	ft_putcstr(char *str, int c);
void	ft_putnstr(char *str, int c);
void	ft_putsstr(char *str, char *substr);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif