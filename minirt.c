/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 08:32:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/15 09:40:37 by fde-capu         ###   ########.fr       */
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
		return (die(FILE_ERROR, ERR_FILE));
	verbose_scene();
	if (!(mlx = ft_mlx_init(g_scn.r.x, g_scn.r.y, WIN_TITLE)))
		return (die(MLX_INIT_ERROR, ERR_MLX_INIT));
	ft_mov(mlx, 250, 250);
	ft_col(mlx, 0xFFFFFF);
	ft_pix(mlx);
	ft_key("q", ftmlx_exit);
	mlx_loop(mlx->mlx);
	return (die(STRANGE_ERROR, ERR_STRANGE));
}

int	die(char *msg, unsigned char err)
{
	if (msg)
		ft_putstr(msg);
	return (err);
}

int	ftmlx_exit(t_mlx *mlx)
{
	ft_putstr(MSG_EXIT);
	ft_mlx_destroy(mlx);
	return (1);
}
