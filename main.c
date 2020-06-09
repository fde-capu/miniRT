/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 05:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 00:46:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// dev notes
// Makefile is missing -WWW

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (1);
}

int	main (int argc, char **argv)
{
	void	*x;
	void	*w;

	ft_putstr("\n\n"WIN_TITLE"\n\n");
	if (!load_rt_file(argv[1], g_scn))
	{
		ft_putstr(FILE_ERROR);
		return (1);
	}
	x = mlx_init();
	w = mlx_new_window(x, 500, 500, WIN_TITLE);
	mlx_pixel_put(x, w, 250, 250, 0xFFFFFF);
	mlx_key_hook(w, deal_key, (void *)0);
	mlx_loop(x);
	(void)w;
	return (0);
}
