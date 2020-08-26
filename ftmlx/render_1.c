/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/26 14:41:19 by fde-capu         ###   ########.fr       */
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

unsigned int	rgb_force(t_rgb rgb, double f)
{
	t_rgb	nrgb;

	nrgb = rgb;
	nrgb.a *= f;
	nrgb.r *= f;
	nrgb.g *= f;
	nrgb.b *= f;
	return (ft_argbtoi(nrgb));
}

unsigned int	skybox(int x, int y)
{
	return (((x * x) + (y * y) - 70) << 16);
}

void	render(t_mrt *mrt, int saving)
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
			if (hit && BONUS)
				color = ft_argbtoi(color_normal(hit));
			if (hit && !BONUS)
			{
			}
			if (!hit && !BONUS)
				color = rgb_force(mrt->scn->ambient.rgb, mrt->scn->ambient.f);
			if (!hit && BONUS)
				color = skybox(x, y);
			ft_pix(mrt, x, y, color);
			intersect_destroy(hit);
			ray_destroy(ray);
			x++;
		}
		y++;
		if (!saving)
			flip(mrt);
	}
	ft_putstr(MSG_DONE);
	return ;
}
