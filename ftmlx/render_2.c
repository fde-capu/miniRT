/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:43:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/26 14:55:31 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

t_ray	*mrt_ray(t_mrt *mrt, int x, int y)
{
	t_vec	*b;
	t_ray	*ray;

	b = pjt_pixtocam(mrt, x, y);
	ray = ray_build(mrt->scn->cam_active->o, b);
	vector_destroy(b);
	return (ray);
}

t_hit	*collision_pix(t_mrt *mrt, t_ray *ray)
{
	t_prm	*primitive;
	double	test;
	t_hit	*hit;
	t_tri	*tri;

	hit = ft_calloc(sizeof(t_hit), 1);
	hit->t = MAX_DEPTH;
	primitive = mrt->scn->primitives;
	while (primitive)
	{
		test = 0.0;
		if (primitive->type == TYPE_SP)
			test = hit_sphere(ray, primitive);
		if (primitive->type == TYPE_PL)
			test = hit_plane(ray, primitive);
		if (primitive->type == TYPE_DS)
			test = hit_disc(ray, primitive);
		if (primitive->type == TYPE_SQ)
			test = hit_square(ray, primitive);
		if (primitive->type == TYPE_CY)
			test = hit_cylinder(ray, primitive);
		if ((test > 0.0) && (test < hit->t))
		{
			hit->t = test;
			hit->primitive = primitive;
			hit->ray = ray;
		}
		primitive = primitive->nx;
	}
	tri = mrt->scn->faces;
	while (tri)
	{
		test = 0.0;
		test = hit_triangle(ray, tri);
		if ((test > 0.0) && (test < hit->t))
		{
			hit->t = test;
			hit->triangle = tri;
			hit->primitive = 0;
			hit->ray = ray;
		}
		tri = tri->nx;
	}
	if (hit->t != MAX_DEPTH)
	{
		intersect_complements(hit);
		return (hit);
	}
	intersect_destroy(hit);
	return (0);
}

void	flip(t_mrt *mrt)
{
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img, 0, 0);
	return ;
}
