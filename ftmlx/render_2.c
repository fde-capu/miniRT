/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:43:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 19:19:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

t_ray	*mrt_ray(t_mrt *mrt, int x, int y)
{
	t_vec	*b;
	t_ray	*ray;

	b = pjt_pixtocam(mrt, x, y);
	verb_cam_active(mrt->scn);
	ray = ray_build(mrt->scn->cam_active->o, b);
	vector_destroy(b);
	return (ray);
}

t_hit	*collision_pix(t_mrt *mrt, t_ray *ray)
{
	t_prm	*primitive;
	t_tri	*tri;
	double	test;
	t_hit	*hit;

	hit = hit_new(MAX_DEPTH);
	primitive = mrt->scn->primitives;
	while (primitive)
	{
		test = hit_primitive(primitive, ray);
		if ((test > 0.0) && (test < hit->t))
			hit_set_primitive(hit, test, primitive, ray);
		primitive = primitive->nx;
	}
	tri = mrt->scn->faces;
	while (tri)
	{
		test = hit_triangle(ray, tri);
		if ((test > 0.0) && (test < hit->t))
			hit_set_triangle(hit, test, triangle, ray);
		tri = tri->nx;
	}
	if (hit->t != MAX_DEPTH)
		return (intersect_complements(hit));
	return (intersect_destroy(hit));
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
