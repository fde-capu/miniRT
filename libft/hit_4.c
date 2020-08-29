/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:16:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 16:15:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hit	*intersect_complements(t_hit *hit)
{
	intersect_phit(hit);
	intersect_normal(hit);
	return (hit);
}

void	intersect_phit(t_hit *hit)
{
	hit->phit = hit_point(hit->ray, hit->t);
	return ;
}

t_vec	*hit_point(t_ray *ray, double t)
{
	t_vec	*hitp;

	hitp = vector_scalar_multiply(ray->d, t);
	hitp = vectorx(hitp, vector_translate(hitp, ray->a));
	return (hitp);
}

void	intersect_normal(t_hit *hit)
{
	if (hit->primitive)
	{
		if (hit->primitive->type == TYPE_SP)
		{
			if (hit_inside_sphere(hit->ray, hit->primitive))
				hit->n = vector_normal_construct(hit->phit, hit->primitive->o);
			else
				hit->n = vector_normal_construct(hit->primitive->o, hit->phit);
			return ;
		}
		if (hit->primitive->type == TYPE_CY)
		{
			hit->n = intersect_cylinder_normal(hit);
			return ;
		}
		hit->n = intersect_normal_generic_primitive(hit);
		return ;
	}
	hit->n = intersect_normal_triangle(hit);
	return ;
}

void	*intersect_destroy(t_hit *hit)
{
	if (!hit)
		return (0);
	if (hit->phit)
		vector_destroy(hit->phit);
	if (hit->n)
		vector_destroy(hit->n);
	free(hit);
	return (0);
}

double	can_see_light(t_mrt *mrt, t_hit *hit, t_vec *l)
{
	double	test;
	t_prm	*primitive;
	t_ray	*ray;
	t_tri	*tri;
	double	light_distance;

	ray = ray_build(hit->phit, l);
	light_distance = vector_vector_distance(hit->phit, l);
	primitive = mrt->scn->primitives;
	while (primitive)
	{
		test = hit_primitive(primitive, ray);
		if (test && test <= light_distance)
			return (ray_destroy_and_return(ray, 0.0));
		primitive = primitive->nx;
	}
	tri = mrt->scn->faces;
	while (tri)
	{
		test = hit_triangle(ray, tri);
		if (test && test <= light_distance)
			return (ray_destroy_and_return(ray, 0.0));
		tri = tri->nx;
	}
	if (hit->primitive && \
		hit->primitive->type == TYPE_SP && \
		hit_inside_sphere(hit->ray, hit->primitive) && \
		vector_vector_distance(hit->primitive->o, l) >
		hit->primitive->h)
		return (ray_destroy_and_return(ray, 0.0));
	return (ray_destroy_and_return(ray, 1.0));
}
