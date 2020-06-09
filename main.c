/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 05:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 07:35:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dev notes
// Makefile is missing -WWW

int	deal_key(int key, void *param)
{
	DEBUG(KEY_RELEASED, NULL, key);
	return (1);
}

int	main(int argc, char **argv)
{
	void	*x;
	void	*w;

	ft_init();
	ft_putstr("\n\n"WIN_TITLE"\n\n");
	if (!load_rt_file(argv[1], &g_scn))
	{
		ft_putstr(FILE_ERROR);
		return (1);
	}
	DEBUG(RX, NULL, g_scn.r.x);
	DEBUG(RY, NULL, g_scn.r.y);
	x = mlx_init();
	w = mlx_new_window(x, g_scn.r.x, g_scn.r.y, WIN_TITLE);
	mlx_pixel_put(x, w, 250, 250, 0xFFFFFF);
	mlx_key_hook(w, deal_key, (void *)0);
	mlx_loop(x);
	(void)w;
	return (0);
}
