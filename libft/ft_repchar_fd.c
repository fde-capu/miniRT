/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:48:56 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 11:49:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_repchar_fd(char c, unsigned int rpt, int fd)
{
	while (rpt)
	{
		ft_putchar_fd(c, fd);
		rpt--;
	}
	return ;
}
