/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:40:07 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/25 16:25:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	ft_key_mrt(t_mrt *mrt, char *key_code, int (*fun)(void*), void *arg)
{
	t_key	*k;

	k = ft_key(key_code, fun, arg);
	mlx_hook(mrt->win, XPRESS, 1L << MPRESS, k->press, 0);
	mlx_hook(mrt->win, XRELEASE, 1L << MRELEASE, k->release, 0);
	return ;
}

t_mrt	*ft_mrt_init(void)
{
	t_mrt	*mrt;

	mrt = ft_calloc(sizeof(t_mrt), 1);
	mrt->mlx = mlx_init();
	return (mrt->mlx ? mrt : 0);
}

int		ft_mrt_init_img(t_mrt *mrt, int res_x, int res_y)
{
	if (!(mrt->img = mlx_new_image(mrt->mlx, res_x, res_y)))
		return 0;
	mrt->i.height = res_y;
	mrt->i.width = res_x;
	mrt->i.address = mlx_get_data_addr(mrt->img, &mrt->i.bpp,	\
		&mrt->i.line_l, &mrt->i.endian);
	return (1);
}

int		ft_mrt_init_win(t_mrt *mrt, int res_x, int res_y, char *win_title)
{
	int		screen_x;
	int		screen_y;

	keys_init();
	mrt->w.width = res_x;
	mrt->w.height = res_y;
	if (FTMLX_LIMIT_WIN_SIZE)
	{
		mlx_get_screen_size(mrt->mlx, &screen_x, &screen_y);
		ft_max2d(&mrt->w.width, &mrt->w.height, screen_x, screen_y);
	}
	mrt->w.title = ft_str(win_title);
	mrt->win = \
		mlx_new_window(mrt->mlx, mrt->w.width, mrt->w.height, mrt->w.title);
	if (!mrt->win)
		return (0);
	return (ft_mrt_init_img(mrt, res_x, res_y));
}

int		ft_mrt_destroy(void *mrtvoid)
{
	t_mrt	*mrt;

	mrt = (t_mrt*)mrtvoid;
	free(mrt->w.title);
	mlx_destroy_image(mrt->mlx, mrt->img);
	mlx_destroy_window(mrt->mlx, mrt->win);
	free(mrt->mlx);
	free(mrt);
	keys_destroy();
	exit(0);
	return (1);
}
