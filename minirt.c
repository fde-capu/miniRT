/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/25 17:23:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_puthex(unsigned char x)
{
	ft_putnbr((int)x);
	return ;
}

#include <stdio.h> //
char	*ft_mrtitobmp(t_mrt *mrt)
{
	char	*h;
	int		x;
	int		y;
	t_rgb	bgra;

	x = 1;
	while (x <= mrt->i.height)
	{
		y = 1;
		while (y <= mrt->i.width)
		{
			h = ft_mov(mrt, x, y);
			bgra = ft_itobgra(*(unsigned int *)h);
			DEBRGB("", bgra);
			printf("\t\t");
			y += 1;
		}
		printf("\n");
		x++;
	}
	return (0);
}

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
		ft_col(mrt, 0x01020304);
		ft_mov(mrt, 1, 1);
		ft_pxi(mrt);
		ft_mov(mrt, 2, 2);
		ft_pxi(mrt);
		ft_mov(mrt, 3, 3);
		ft_pxi(mrt);
//		ft_mov(mrt, 4, 4);
//		ft_pxi(mrt);
		int	size = sizeof(t_bmp) + (mrt->i.line_l * mrt->i.height);
		t_bmp *bmp = ft_calloc(size, 1);
		bmp->file_header.bftype = 19778;
		bmp->file_header.bfsize = size;
		DEBINT("ln_l", mrt->i.line_l);
		DEBINT("pixs", (mrt->i.line_l * mrt->i.height));
		DEBINT("size", size);
		bmp->file_header.bfoffs = sizeof(t_bmp);
		bmp->info_header.bisize = sizeof(t_bmih);
		bmp->info_header.biwidth = g_scn->resolution.x;
		bmp->info_header.biheight = g_scn->resolution.y;
		bmp->info_header.biplanes = 1;
		bmp->info_header.bpp = mrt->i.bpp;
		ft_mrtitobmp(mrt);
//		int	fp;
//		if ((fp = open("test.bmp", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
//			die ("Could not open file for writing.", 10);
//		write(fp, bmp, sizeof(t_bmp));
//		write(fp, ft_mrtitobmp(mrt), (mrt->i.line_l * mrt->i.height));
//		close (fp);
		ft_putstr(MSG_SAVED);
		ft_putstr(SAVE_FN);
		ft_putstr("\n");
		return (minirt_exit(0));
	}
	if (!ft_mrt_init_win(mrt, g_scn->resolution.x, g_scn->resolution.y,
		WIN_TITLE))
		return (die(WIN_ERROR, ERR_WIN));
	g_mrt = mrt;
	ft_key_mrt(mrt, KEY_QUIT1, minirt_exit, mrt);
	ft_key_mrt(mrt, KEY_QUIT2, minirt_exit, mrt);
	ft_key_mrt(mrt, KEY_CAM_UP, change_cam_up, g_scn);
	ft_key_mrt(mrt, KEY_CAM_DOWN, change_cam_down, g_scn);
	mlx_do_key_autorepeatoff(mrt->mlx);
	mlx_hook(mrt->win, 17, 1L << 17, minirt_exit, mrt);
	ft_mov(mrt, 1, 1);
	ft_col(mrt, 0x000022FF);
	ft_pxi(mrt);
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	ft_mov(mrt, 3, 3);
	ft_pxw(mrt);
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
