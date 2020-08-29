/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 16:21:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

/*
**      v v v d   rgb  d  d i     v v v
** cam	o p n fov
** lht	o     f   rgb
** prm  o   n     rgb  h  d type
** tri  o   n     rgb             a b c
*/

unsigned int	hit_and_bonus_color(t_mrt *mrt, t_hit *hit, int x, int y)
{
	if (hit && BONUS)
		return (ft_argbtoi(color_normal(hit)));
	if (hit && !BONUS)
		return (color_trace(mrt, hit));
	if (!hit && !BONUS)
		return (color_force(mrt->scn->ambient.rgb, mrt->scn->ambient.f));
	if (!hit && BONUS)
		return (skybox(x, y));
	return (0);
}

void			render(t_mrt *mrt, int saving)
{
	int				x;
	int				y;
	t_ray			*ray;
	t_hit			*hit;
	unsigned int	color;

	ft_putstr(MSG_RENDERING);
	y = 0;
	while (++y <= mrt->i.height)
	{
		x = 0;
		while (++x <= mrt->i.width)
		{
			ray = mrt_ray(mrt, x, y);
			hit = collision_pix(mrt, ray);
			color = hit_and_bonus_color(mrt, hit, x, y);
			ft_pix(mrt, x, y, color);
			intersect_destroy(hit);
			ray_destroy(ray);
		}
	}
	if (!saving)
		flip(mrt);
	ft_putstr(MSG_DONE);
	return ;
}
