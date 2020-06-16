/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:55:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/16 08:26:17 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	x;
	int		w;

	x = (long)n;
	if (x < 0)
	{
		x *= -1;
		write(fd, "-", 1);
	}
	if (x < 10)
	{
		w = (int)x + '0';
		write(fd, &w, 1);
		return ;
	}
	ft_putnbr_fd(x / 10, fd);
	x %= 10;
	w = (int)x + '0';
	write(fd, &w, 1);
	return ;
}

void		ft_putnbr(int n)
{
	return (ft_putnbr_fd(n, 1));
}
