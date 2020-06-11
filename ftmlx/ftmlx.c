/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/11 14:06:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	key_hook(t_mlx *mlx, int k)
{
	mlx_hook(mlx->mlx, 1L << XPRESS, 1L << MPRESS, key(k)->on_press, 0);
	mlx_hook(mlx->mlx, 1L << XRELEASE, 1L << MRELEASE, key(k)->on_release, 0);
	return ;
}

void	hook_keys(t_mlx *mlx, int ks, int ke)
{
	int	i;

	i = ks;
	while (i <= ke)
		key_hook(mlx, i++);
	return ;
}

t_mlx	*ft_mlx_init(int res_x, int res_y, char *win_title)
{
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	mlx->mlx = mlx_init();
	keys_init();
	hook_keys(mlx, KEYS_FIRST, KEYS_LAST);
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
	return (0);
}
