/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 14:52:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	key_hook_toggle(t_mlx *mlx, int key)
{
//	mlx_hook();
	(void)mlx;
	(void)key;
	return ;
}

void	hook_toggles(t_mlx *mlx, int ks, int ke)
{
	int	i;

	i = ks;
	while (i <= ke)
		key_hook_toggle(mlx, i);
	return ;
}

t_mlx	*ft_mlx_init(int res_x, int res_y, char *win_title)
{
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);	
	mlx->mlx = mlx_init();
	if(!mlx->mlx)
		return (0);
	mlx->w.width = res_x;
	mlx->w.height = res_y;
	mlx->w.title = ft_str(win_title);
	mlx->win = mlx_new_window(mlx->mlx, mlx->w.width, mlx->w.height, mlx->w.title);
	if(!mlx->win)
		return (0);
	hook_toggles(mlx, 0, 0xffff);
	return (mlx);
}

int		ft_mlx_destroy(t_mlx *mlx)
{
	free(mlx->w.title);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	return (0);
}
