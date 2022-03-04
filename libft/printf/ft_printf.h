/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:23:14 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/08/01 22:23:15 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_parameters
{
	int	type;
	int	width;
	int	preci;
}	t_param;

typedef struct s_modes
{
	bool	preci;
	bool	zero;
	bool	minus;
}	t_mode;

typedef struct s_tools
{
	int		len;
	int		p_len;
	t_param	param;
	t_mode	mode;
}	t_tool;

int		ft_printf(char *form, ...);
void	ft_putchar(char c);

#endif