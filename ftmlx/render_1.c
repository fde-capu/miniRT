/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/24 13:10:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

/*
**      v v v d   rgb  d  d i     v v v
** cam	o p n fov
** lht	o     f   rgb
** prm  o   n     rgb  h  d type
** tri      n     rgb             a b c
*/

void	render(t_mrt *mrt)
{
	int				x;
	int				y;
	t_ray			*ray;
	t_hit			*hit;
	unsigned int	color;

	ft_putstr(MSG_RENDERING);
	y = 1;
	while (y <= mrt->i.height)
	{
		x = 1;
		while (x <= mrt->i.width)
		{
			ray = mrt_ray(mrt, x, y);
			hit = collision_pix(mrt, ray);
			if (hit)
			{
//				DEBVEC("cn", hit->n);
				if (hit->primitive->type == TYPE_SP)
					color = ft_argbtoi(color_normal(hit));
				if ((hit->primitive->type == TYPE_SQ) || (hit->primitive->type == TYPE_PL))
					color = ft_argbtoi(color_blend(color_distance(hit), color_normal(hit), 0.5));
				// compute color at intersection point
				ft_pix(mrt, x, y, color);
			}
			else
			{
				// draw background
				ft_pix(mrt, x, y, (x * y / 2) << 16);
			}
			intersect_destroy(hit);
			ray_destroy(ray);
			flip(mrt);
			x++;
		}
		y++;
	}
	return ;
}
