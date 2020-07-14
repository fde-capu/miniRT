/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:43:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/07/14 16:44:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

int		collision_pix(t_mrt *mrt, int x, int y)
{
	t_prm	*p;

	// for evey object (prm and tri)
	//		find intersections
	//		keep if closest
	p = mrt->scn->primitives;
	while (p)
	{
		p = p->nx;
	}
	(void)x;
	(void)y;
	return (0);
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
