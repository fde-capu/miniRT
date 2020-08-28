/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:32:27 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 19:19:33 by fde-capu         ###   ########.fr       */
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

unsigned int	hit_and_bonus_color(t_mrt *mrt, t_hit *hit)
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
			color = hit_and_bonus_color(mrt, hit);
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

double			hit_primitive(t_prm *primitive, t_ray *ray)
{
	if (primitive->type == TYPE_SP)
		return (hit_sphere(ray, primitive));
	if (primitive->type == TYPE_PL)
		return (hit_plane(ray, primitive));
	if (primitive->type == TYPE_DS)
		return (hit_disc(ray, primitive));
	if (primitive->type == TYPE_CY)
		return (hit_cylinder(ray, primitive));
	return (0.0);
}

double			hit_triangle(t_ray *ray, t_tri *tri)
{
	t_prm	*plane;
	t_vec	*plane_n;
	t_vec	*pos[3];
	double	t;
	t_vec	*hit;

	plane_n = triangle_normal(tri);
	plane = plane_init(tri->a, plane_n, ft_rgb(0.0, 0.0, 0.0, 0.0));
	t = hit_plane(ray, plane);
	hit = hit_point(ray, t);
	pos[0] = hit_triangle_crosshit(hit, tri->b, tri->a);
	pos[1] = hit_triangle_crosshit(hit, tri->c, tri->b);
	pos[2] = hit_triangle_crosshit(hit, tri->a, tri->c);
	if ((vector_dot_product(plane_n, pos[0]) <= 0.0)
		|| (vector_dot_product(plane_n, pos[1]) <= 0.0)
		|| (vector_dot_product(plane_n, pos[2]) <= 0.0))
		t = 0.0;
	destroy_hit_triangle(hit, pos, plane, plane_n);
	return (hit_minimal(t));
}
