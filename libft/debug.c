/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:00:22 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/22 17:03:10 by fde-capu         ###   ########.fr       */
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

void	debug(char *str, char *val, int *ival)
{
	if (!debug_pass())
		return ;
	return (debug_body(str, val ? val : 0, ival ? *ival : 0));
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
