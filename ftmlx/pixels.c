/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:38:48 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/25 16:20:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void			ft_pxi(t_mrt *mrt)
{
	*(mrt->icursor + 0) = mrt->color.a;
	*(mrt->icursor + 1) = mrt->color.r;
	*(mrt->icursor + 2) = mrt->color.g;
	*(mrt->icursor + 3) = mrt->color.b;
	return ;
}

void			ft_pxw(t_mrt *mrt)
{
	mlx_pixel_put(mrt->mlx, mrt->win, mrt->cursor.x, mrt->cursor.y,
		ft_argbtoi(mrt->color));
	return ;
}

char			*ft_mov(t_mrt *mrt, int x, int y)
{
	mrt->cursor.x = x;
	mrt->cursor.y = y;
	mrt->icursor = mrt->i.address + ((y * mrt->i.line_l) + (x * (mrt->i.bpp / 8)));
	return (mrt->icursor);
}

void			ft_col(t_mrt *mrt, unsigned int color)
{
	mrt->color = ft_itoargb(color);
}
