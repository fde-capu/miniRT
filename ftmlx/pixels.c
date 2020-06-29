/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:38:48 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 15:31:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void			ft_pxi(t_mrt *mrt)
{
	*(mrt->icursor + 0) = mrt->color.b;
	*(mrt->icursor + 1) = mrt->color.g;
	*(mrt->icursor + 2) = mrt->color.r;
	*(mrt->icursor + 3) = mrt->color.a;
	return ;
}

char			*ft_mov(t_mrt *mrt, int x, int y)
{
	x--;
	y--;
	mrt->cursor.x = x;
	mrt->cursor.y = y;
	mrt->icursor = mrt->i.address + \
		((y * mrt->i.line_l) + (x * (mrt->i.bpp / 8)));
	return (mrt->icursor);
}

void			ft_col(t_mrt *mrt, unsigned int color)
{
	mrt->color = ft_itoargb(color);
}
