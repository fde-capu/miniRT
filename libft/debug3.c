/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:07:49 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/17 08:33:19 by fde-capu         ###   ########.fr       */
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

void	debug_str_str(char *str1, char *str2)
{
	if (!debug_pass())
		return ;
	ft_putstr(str1);
	ft_putstr(DEB_DIV);
	ft_putstr(str2);
	ft_putstr("\n");
	return ;
}
