/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/22 14:37:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dev notes
// ftmlx ==> Makefile is missing -WWW

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	void	*x;
	void	*w;
	int		err;

	g_mlx = 0;
	g_scn = 0;
	ft_init();
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
	ft_key_mlx(mlx, KEY_QUIT, minirt_exit, mlx);
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
	scene_destroy(g_scn);
	ft_mlx_destroy((t_mlx*)mlx);
	ft_putstr(MSG_EXIT);
	exit(0);
	return (0);
}
