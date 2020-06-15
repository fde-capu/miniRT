/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 08:50:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	ft_key_hook(t_mlx *mlx, int k, int (*fun)(int))
{
	mlx_hook(mlx->win, XPRESS, 1L << MPRESS, on_press, fun);
	mlx_hook(mlx->win, XRELEASE, 1L << MRELEASE, on_release, fun);
	return ;
}

t_mlx	*ft_mlx_init(int res_x, int res_y, char *win_title)
{
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	mlx->mlx = mlx_init();
	keys_init();
	if (!mlx->mlx)
		return (0);
	mlx->w.width = res_x;
	mlx->w.height = res_y;
	mlx->w.title = ft_str(win_title);
	mlx->win = \
		mlx_new_window(mlx->mlx, mlx->w.width, mlx->w.height, mlx->w.title);
	if (!mlx->win)
		return (0);
	return (mlx);
}

int		ft_mlx_destroy(t_mlx *mlx)
{
	free(mlx->w.title);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	return (1);
}
