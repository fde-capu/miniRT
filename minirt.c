/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/23 15:46:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dev notes
// XIO: Fatal IO error 11 on close by Alt+F4 or (x) button.
// ft_mlx_init currently mlx_get_screen_size is not found.

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	(void)argc;
	g_mlx = 0;
	g_scn = 0;
	g_scn = scene_init();
	ft_putstr("\n\n"WIN_TITLE"\n\n");
	if (!load_rt_file(argv[1], g_scn))
		return (die(FILE_ERROR, ERR_FILE));
	verbose_scene(g_scn);
	if (!(mlx = ft_mlx_init(g_scn->resolution.x, g_scn->resolution.y,
		WIN_TITLE)))
		return (die(MLX_INIT_ERROR, ERR_MLX_INIT));
	g_mlx = mlx;
	ft_mov(mlx, 250, 250);
	ft_col(mlx, 0xFFFFFF);
	ft_pix(mlx);
	ft_key_mlx(mlx, KEY_QUIT1, minirt_exit, mlx);
	ft_key_mlx(mlx, KEY_QUIT2, minirt_exit, mlx);
	ft_key_mlx(mlx, KEY_CAM, change_cam, g_scn);
	mlx_do_key_autorepeatoff(mlx->mlx);
	mlx_hook(mlx->win, 17, 1L << 17, minirt_exit, mlx);
	mlx_loop(mlx->mlx);
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
	if (g_mlx)
		ft_mlx_destroy(g_mlx);
	ft_putstr("\n");
	exit(err);
	return (0);
}

int	minirt_exit(void *mlx)
{
	ft_putstr(MSG_EXIT);
	scene_destroy(g_scn);
	ft_mlx_destroy((t_mlx*)mlx);
	exit(0);
	return (0);
}
