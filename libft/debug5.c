/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:51:51 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 14:52:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_str_add(char *str, void *add)
{
	char	*o;

	if (!debug_pass())
		return ;
	debug_str(str, add);
	ft_putstr("\b");
	ft_putstr(DEB_DIV);
	o = ft_ptoa(&add);
	ft_putstr(o);
	ft_putstr("\n");
	free(o);
	return ;
}
