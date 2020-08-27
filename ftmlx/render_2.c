/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:43:02 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 02:33:30 by fde-capu         ###   ########.fr       */
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

double		can_see_light(t_mrt *mrt, t_hit *hit, t_vec *l)
{
	double	test;
	t_prm	*primitive;
	t_ray	*ray;
	t_tri	*tri;
	t_vec	*o;

	o = hit->phit;
	ray = ray_build(o, l);
	if (vector_dot_product(hit->ray->d, hit->n) > 0.0)
		return (0.0);
	test = 0.0;
	primitive = mrt->scn->primitives;
	while (primitive)
	{
		if (primitive->type == TYPE_SP)
			test = hit_sphere(ray, primitive);
		if (primitive->type == TYPE_PL)
			test = hit_plane(ray, primitive);
		if (primitive->type == TYPE_DS)
			test = hit_disc(ray, primitive);
		if (primitive->type == TYPE_CY)
			test = hit_cylinder(ray, primitive);
		if (test)
			return (0.0);
		primitive = primitive->nx;
	}
	tri = mrt->scn->faces;
	while (tri)
	{
		test = hit_triangle(ray, tri);
		if (test)
			return (0.0);
		tri = tri->nx;
	}
	ray_destroy(ray);
	return (1.0);
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
