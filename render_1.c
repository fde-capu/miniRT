/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/30 08:53:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		collision_pix(t_mrt *mrt, int x, int y)
{
	t_prm	*p;

	p = mrt->scn->primitives;
	while (p)
	{
		p = p->nx;
	}
	(void)x;
	(void)y;
	return (0);
}

void	render(t_mrt *mrt)
{
	int	x;
	int	y;

	ft_putstr(MSG_RENDERING);
	y = 1;
	while (y <= mrt->i.height)
	{
		x = 1;
		while (x <= mrt->i.width)
		{
			if (collision_pix(mrt, x, y))
				ft_pix(mrt, x, y, (x*y/2)<<16);
			x++;
		}
		y++;
	}
	return ;
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
