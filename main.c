/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 05:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/10 15:04:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dev notes
// ftmlx ==> Makefile is missing -WWW

int	deal_key(int key, void *param)
{
	DEBINT(MSG_KEY_RELEASED, key);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	void	*x;
	void	*w;
	int		err;

	ft_init();
	ft_putstr("\n\n"WIN_TITLE"\n\n");
	if (!load_rt_file(argv[1], &g_scn))
	{
		ft_putstr(FILE_ERROR);
		return (1);
	}
	DEBINT(MSG_RX, g_scn.r.x);
	DEBINT(MSG_RY, g_scn.r.y);
	DEBDBL("amb force", g_scn.a.f);
	DEBRGB("amb rgb", g_scn.a.rgb);
	DEBD3D("cam origin", g_scn.c.o);
	DEBVEC("cam point", g_scn.c.p);
	DEBDBL("cam fov", g_scn.c.fov);
	mlx = ft_mlx_init(g_scn.r.x, g_scn.r.y, WIN_TITLE);
	if (!mlx)
		return (1);
	ft_mov(mlx, 250, 250);
	ft_col(mlx, 0xFFFFFF);
	ft_pix(mlx);
//	mlx_key_hook(mlx.win, deal_key, (void *)0);
	mlx_loop(mlx->mlx);
	ft_mlx_destroy(mlx);
	return (0);
}
