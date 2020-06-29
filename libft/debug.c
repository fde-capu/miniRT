/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:00:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 09:50:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		debug_pass(void)
{
	if (DEBUG_FLAG)
		return (1);
	if (VERBOSE_FLAG)
		return (1);
	return (0);
}

void	debug_str_only(char *str)
{
	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr("\n");
	return ;
}

void	debug_str(char *str, char *val)
{
	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	ft_putstr(DEB_STR_ENCLOSURE);
	ft_putstr(val);
	ft_putstr(DEB_STR_ENCLOSURE);
	ft_putstr("\n");
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

void	debug_str2(char *str, char *val, char *val2)
{
	if (!debug_pass())
		return ;
	ft_putstr(str);
	ft_putstr(DEB_DIV);
	ft_putstr(DEB_STR_ENCLOSURE);
	ft_putstr(val);
	ft_putstr(DEB_STR_ENCLOSURE);
	ft_putstr(DEB_DIV);
	ft_putstr(DEB_STR_ENCLOSURE);
	ft_putstr(val2);
	ft_putstr(DEB_STR_ENCLOSURE);
	ft_putstr("\n");
	return ;
}
