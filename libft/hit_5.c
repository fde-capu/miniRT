/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 05:11:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 17:13:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int			hit_cylinder_outside(t_hit *hit)
{
	double	dp;
	t_vec	*ruler;

	ruler = vector_normal_construct(hit->primitive->o, hit->phit);
	dp = vector_dot_product(ruler, hit->ray->d);
	vector_destroy(ruler);
	return (dp < 0.0 ? 1 : 0);
}

t_vec		*intersect_cylinder_normal(t_hit *hit)
{
	t_vec	*vec;
	double	d;

	vec = vector_subtract(hit->phit, hit->primitive->o);
	d = vector_dot_product(hit->primitive->n, vec);
	vec = vectorx(vec, vector_scalar_multiply(hit->primitive->n, d));
	vec = vectorx(vec, vector_sum(vec, hit->primitive->o));
	if (hit_cylinder_outside(hit))
		hit->n = vector_normal_construct(vec, hit->phit);
	else
		hit->n = vector_normal_construct(hit->phit, vec);
	vector_destroy(vec);
	return (hit->n);
}
