/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 17:44:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	ft_key_mlx(t_mlx *mlx, char *key_code, int (*fun)(void*), void *arg)
{
	t_key	*k;

	k = ft_key(key_code, fun, arg);
	mlx_hook(mlx->win, XPRESS, 1L << MPRESS, k->press, 0);
	mlx_hook(mlx->win, XRELEASE, 1L << MRELEASE, k->release, 0);
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

int		ft_mlx_destroy(void *mlxvoid)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)mlxvoid;
	free(mlx->w.title);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	free(mlx);
	keys_destroy();
	exit(0);
	return (1);
}
