/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:38:48 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 14:52:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	ft_pix(t_mlx *mlx)
{
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->cursor.x, mlx->cursor.y,
		ft_rgbtoi(mlx->color));
	return ;
}

void	ft_mov(t_mlx *mlx, int x, int y)
{
	mlx->cursor.x = x;
	mlx->cursor.y = y;
	return ;
}

void	ft_col(t_mlx *mlx, int color)
{
	mlx->color = ft_itorgb(color);
}
