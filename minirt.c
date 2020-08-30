/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 00:07:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mrt_win_binds(t_mrt *mrt)
{
	ft_key_mrt(mrt, KEY_QUIT1, minirt_exit, mrt);
	ft_key_mrt(mrt, KEY_QUIT2, minirt_exit, mrt);
	ft_key_mrt(mrt, KEY_CAM_UP, change_cam_up, mrt->scn);
	ft_key_mrt(mrt, KEY_CAM_DOWN, change_cam_down, mrt->scn);
	ft_key_mrt(mrt, KEY_SCALE_UP, scale_up, mrt->scn);
	ft_key_mrt(mrt, KEY_SCALE_DOWN, scale_down, mrt->scn);
	ft_key_mrt(mrt, KEY_TRANS_UP, translate_all_up, mrt->scn);
	ft_key_mrt(mrt, KEY_TRANS_DOWN, translate_all_down, mrt->scn);
	ft_key_mrt(mrt, KEY_ROT_UP, rotate_all_obj, mrt->scn);
	ft_key_mrt(mrt, KEY_ROT_DOWN, rotate_active_cam, mrt->scn);
	mlx_do_key_autorepeatoff(mrt->mlx);
	mlx_hook(mrt->win, 17, 1L << 17, minirt_exit, mrt);
	return ;
}

int		main(int argc, char **argv)
{
	t_mrt	*mrt;

	if (!(mrt = ft_mrt_init()))
		die(0, MLX_INIT_ERROR, ERR_MLX_INIT);
	g_mrt = mrt;
	mrt->scn = scene_init();
	ft_putstr("\n\n"WIN_TITLE"\n\n");
	if (!load_rt_file(argv[1], mrt->scn))
		die(mrt, FILE_ERROR, ERR_FILE);
	die_if_random_error(mrt);
	verbose_scene(mrt->scn);
	if (!ft_mrt_init_img(mrt))
		die(mrt, IMG_ERROR, ERR_IMG);
	if (ft_args(argc, argv, "--save"))
		minirt_exit(save_mrttobmp(mrt, SAVE_FN));
	if (!ft_mrt_init_win(mrt, WIN_TITLE))
		die(mrt, WIN_ERROR, ERR_WIN);
	mrt_win_binds(mrt);
	render(mrt, 0);
	flip(mrt);
	mlx_loop(mrt->mlx);
	return (die(mrt, STRANGE_ERROR, ERR_STRANGE));
}

int		die(t_mrt *mrt, char *msg, unsigned char err)
{
	ft_putstr(ERROR_STR_A);
	ft_putnbr(err);
	ft_putstr(ERROR_STR_B);
	if (msg)
		ft_putstr(msg);
	ft_putstr("\n");
	if (mrt)
	{
		scene_destroy(mrt->scn);
		ft_mrt_destroy(mrt);
	}
	ft_putstr("\n");
	exit(err);
	return (0);
}

int		minirt_exit(void *mrt)
{
	ft_putstr(MSG_EXIT);
	if ((t_mrt *)mrt)
	{
		scene_destroy(((t_mrt *)mrt)->scn);
		ft_mrt_destroy((t_mrt *)mrt);
	}
	exit(0);
	return (0);
}
