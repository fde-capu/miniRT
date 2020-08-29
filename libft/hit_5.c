/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 05:11:47 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 15:40:36 by fde-capu         ###   ########.fr       */
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

t_vec	*vector_inverse_translate(t_vec *vec, t_vec *trans)
{
	t_vec	*inv;
	t_vec	*copy;

	copy = vector_copy(vec);
	inv = vector_scalar_multiply(trans, -1.0);
	copy = vectorx(copy, vector_translate(copy, inv));
	vector_destroy(inv);
	return (copy);
}

t_vec		*intersect_cylinder_normal(t_hit *hit)
{
	t_vec	*phit;
	t_vec	*pcenter;
	double	d;
	t_vec	*pre_n;

	phit = vector_inverse_translate(hit->phit, hit->primitive->o);
	d = vector_dot_product(hit->primitive->n, phit);
	pcenter = vector_scalar_multiply(hit->primitive->n, d);
	pre_n = vector_normal_construct(pcenter, phit);
	if (vector_dot_product(hit->ray->d, pre_n) > 0.0)
		pre_n = vectorx(pre_n, vector_normal_construct(phit, pcenter));
	hit->n = pre_n;
	vector_destroy(phit);
	vector_destroy(pcenter);
	return (hit->n);
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
