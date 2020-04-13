/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 05:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/04/13 15:53:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include <mlx.h>

int	main (void)
{
	void	*x;
	void	*w;

	printf("miniRT by fde-capu\n");//
	x = mlx_init();
	w = mlx_new_window(x, 500, 500, "miniRT by fde-capu");
	mlx_loop(x);
	return (0);
}
