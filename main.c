/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 05:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/08 16:42:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//int	deal_key(int key, void *param)
//{
//	ft_putchar('X');
//

int	main (void)
{
	void	*x;
	void	*w;

//	ft_putstr("miniRT by fde-capu\n");
	x = mlx_init();
	w = mlx_new_window(x, 500, 500, "miniRT by fde-capu");
//	mlx_pixel_put(x, w, 250, 250, 0x0000FF);
//	mlx_key_hook(w, deal_key, (void *)0);
	mlx_loop(x);
	(void)w;
	return (0);
}
