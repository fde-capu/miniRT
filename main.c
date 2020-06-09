/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 05:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/08 22:15:26 by fde-capu         ###   ########.fr       */
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

int	main (void)
{
	void	*x;
	void	*w;

	ft_putstr(WIN_TITLE"\n");
	x = mlx_init();
	w = mlx_new_window(x, 500, 500, WIN_TITLE);
//	mlx_pixel_put(x, w, 250, 250, 0x0000FF);
//	mlx_key_hook(w, deal_key, (void *)0);
	mlx_loop(x);
	(void)w;
	return (0);
}
