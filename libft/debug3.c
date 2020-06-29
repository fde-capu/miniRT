/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:07:49 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 09:57:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_int2(char *str, int val, int val2)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	o = ft_itoa(val);
	ft_putstr(o);
	ft_putstr(DEB_DIV);
	o = ft_x(o, ft_itoa(val2));
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}

void	subdebug_int2(char *str, int val, int val2, int subdeb)
{
	if (subdeb)
		return (debug_int2(str, val, val2));
	return ;
}

void	debug_int(char *str, int val)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	o = ft_itoa(val);
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}

void	subdebug_int(char *str, int val, int subdeb)
{
	if (subdeb)
		return (debug_int(str, val));
	return ;
}

void	debug_double(char *str, double val)
{
	char	*o;

	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	o = ft_dtoa(val);
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}
