/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:26:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/17 16:52:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_die(const char *msg, int err)
{
	char	*a;

	a = ft_itoa(err);
	ft_putstr(a);
	ft_putstr(" ");
	ft_putstr((char *)msg);
	ft_putstr("\n");
	exit(err);
}
