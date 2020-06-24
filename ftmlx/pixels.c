/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:38:48 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 15:48:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	ft_pxi(t_mrt *mrt)
{
	*mrt->icursor = ft_rgbtoi(mrt->color);
	return ;
}

void	ft_pxw(t_mrt *mrt)
{
	mlx_pixel_put(mrt->mlx, mrt->win, mrt->cursor.x, mrt->cursor.y,
		ft_rgbtoi(mrt->color));
	return ;
}

void	ft_mov(t_mrt *mrt, int x, int y)
{
	mrt->cursor.x = x;
	mrt->cursor.y = y;
	mrt->icursor = mrt->i.address + (y * mrt->i.line_l + x * (mrt->i.bpp / 8));
	return ;
}

void	ft_col(t_mrt *mrt, int color)
{
	mrt->color = ft_itorgb(color);
}
