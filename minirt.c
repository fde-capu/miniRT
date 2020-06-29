/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 09:11:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_puthex(unsigned char x)
{
	ft_putnbr((int)x);
	return ;
}

int		ft_mrtitobmp(t_mrt *mrt, int fp)
{
	char	*h;
	int		x;
	int		y;
	t_rgb	argb;
	int		buf;
	int		*n;

	buf = 0;
	x = 1;
	while (x <= mrt->i.height)
	{
		y = 1;
		while (y <= mrt->i.width)
		{
			h = ft_mov(mrt, x, y);
			argb = ft_itobgra(*(unsigned int *)h);
			n = ft_calloc(sizeof(int), 1);
			*n = ft_argbtoi(argb);
			write(fp, (void *)n, sizeof(int));
			free(n);
			DEBRGB("", argb);
			y += 1;
		}
		y--;
		while (y++ % 4)
			write(fp, 0, sizeof(int));
		x++;
	}
	return (buf);
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
		ft_col(mrt, 0x00FFFFFF);
		ft_mov(mrt, 2, 2);
		ft_pxi(mrt);
		ft_mov(mrt, 3, 3);
		ft_pxi(mrt);
		int	size = 14 + 40 + ((mrt->i.width * mrt->i.height) * sizeof(int));
		DEBINT("size", size);
		t_bmp *bmp = ft_calloc(sizeof(t_bmp), 1);
		bmp->file_header.bftype = 19778;
		bmp->file_header.bfsize = size;
		bmp->file_header.bfoffs = 14 + 40;
		bmp->info_header.bisize = 40;
		bmp->info_header.biwidth = g_scn->resolution.x;
		bmp->info_header.biheight = g_scn->resolution.y;
		bmp->info_header.biplanes = 1;
		bmp->info_header.bpp = mrt->i.bpp;
		int	fp;
		if ((fp = open("test.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
			die ("Could not open file for writing.", 10);
		write(fp, &bmp->file_header.bftype, sizeof((t_bmfh *)0)->bftype);
		write(fp, &bmp->file_header.bfsize, sizeof((t_bmfh *)0)->bfsize);
		write(fp, &bmp->file_header.zeros1, sizeof((t_bmfh *)0)->zeros1);
		write(fp, &bmp->file_header.zeros2, sizeof((t_bmfh *)0)->zeros2);
		write(fp, &bmp->file_header.bfoffs, sizeof((t_bmfh *)0)->bfoffs);
		write(fp, &bmp->info_header.bisize, sizeof((t_bmih *)0)->bisize);
		write(fp, &bmp->info_header.biwidth, sizeof((t_bmih *)0)->biwidth);
		write(fp, &bmp->info_header.biheight, sizeof((t_bmih *)0)->biheight);
		write(fp, &bmp->info_header.biplanes, sizeof((t_bmih *)0)->biplanes);
		write(fp, &bmp->info_header.bpp, sizeof((t_bmih *)0)->bpp);
		write(fp, &bmp->info_header.bicompress, sizeof((t_bmih *)0)->bicompress);
		write(fp, &bmp->info_header.bisizeimg, sizeof((t_bmih *)0)->bisizeimg);
		write(fp, &bmp->info_header.bixppmeter, sizeof((t_bmih *)0)->bixppmeter);
		write(fp, &bmp->info_header.biyppmeter, sizeof((t_bmih *)0)->biyppmeter);
		write(fp, &bmp->info_header.binumofcolors, sizeof((t_bmih *)0)->binumofcolors);
		write(fp, &bmp->info_header.biimportantcolors, sizeof((t_bmih *)0)->biimportantcolors);
		ft_mrtitobmp(mrt, fp);
		close (fp);
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
