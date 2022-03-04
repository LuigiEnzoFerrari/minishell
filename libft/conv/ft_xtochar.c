/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtochar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:32:24 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 17:26:00 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_xtochar(unsigned int n)
{
	n %= 16;
	if (n >= 10)
		n += 87;
	else
		n += 48;
	return (n);
}