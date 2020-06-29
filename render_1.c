/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/29 15:35:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_mrt *mrt)
{
	ft_putstr(MSG_RENDERING);
	ft_col(mrt, 0x00FF0000);
	ft_mov(mrt, 1, 1);
	ft_pxi(mrt);
	ft_col(mrt, 0x0000FF00);
	ft_mov(mrt, 2, 2);
	ft_pxi(mrt);
	ft_col(mrt, 0x000000FF);
	ft_mov(mrt, 3, 3);
	ft_pxi(mrt);
	return ;
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
