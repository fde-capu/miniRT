/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/24 16:01:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dev notes
// XIO: Fatal IO error 11 on close by Alt+F4 or (x) button.
// ft_mrt_init currently mlx_get_screen_size is not found.

int	main(int argc, char **argv)
{
	t_mrt	*mrt;

	(void)argc;
	g_mrt = 0;
	g_scn = 0;
	g_scn = scene_init();
	ft_putstr("\n\n"WIN_TITLE"\n\n");
	if (!load_rt_file(argv[1], g_scn))
		return (die(FILE_ERROR, ERR_FILE));
	verbose_scene(g_scn);
	if (!(mrt = ft_mrt_init()))
		die(MLX_INIT_ERROR, ERR_MLX_INIT);
	if (ft_args(argc, argv, "--save"))
	{
		if (!ft_mrt_init_img(mrt, g_scn->resolution.x, g_scn->resolution.y))
			die(IMG_ERROR, ERR_IMG);
		ft_putstr(MSG_SAVED);
		ft_putstr(SAVE_FN);
		ft_putstr("\n");
		return (minirt_exit(0));
	}
	if (!ft_mrt_init_win(mrt, g_scn->resolution.x, g_scn->resolution.y,
		WIN_TITLE))
		return (die(WIN_ERROR, ERR_WIN));
	g_mrt = mrt;
	ft_mov(mrt, 250, 250);
	ft_col(mrt, 0xFFFFFF);
	ft_pxw(mrt);
	ft_key_mrt(mrt, KEY_QUIT1, minirt_exit, mrt);
	ft_key_mrt(mrt, KEY_QUIT2, minirt_exit, mrt);
	ft_key_mrt(mrt, KEY_CAM_UP, change_cam_up, g_scn);
	ft_key_mrt(mrt, KEY_CAM_DOWN, change_cam_down, g_scn);
	mlx_do_key_autorepeatoff(mrt->mlx);
	mlx_hook(mrt->win, 17, 1L << 17, minirt_exit, mrt);
	mlx_loop(mrt->mlx);
	return (die(STRANGE_ERROR, ERR_STRANGE));
}

int	die(char *msg, unsigned char err)
{
	ft_putnbr(err);
	ft_putstr(": ");
	if (msg)
		ft_putstr(msg);
	ft_putstr("\n");
	if (g_scn)
		scene_destroy(g_scn);
	if (g_mrt)
		ft_mrt_destroy(g_mrt);
	ft_putstr("\n");
	exit(err);
	return (0);
}

int	minirt_exit(void *mrt)
{
	ft_putstr(MSG_EXIT);
	if (g_scn)
		scene_destroy(g_scn);
	if (g_mrt)
		ft_mrt_destroy(g_mrt);
	(void)mrt;
	exit(0);
	return (0);
}
