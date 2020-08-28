/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:16:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 15:17:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hit	*intersect_complements(t_hit *hit)
{
	intersect_phit(hit);
	intersect_normal(hit);
	return (hit);
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

t_vec	*hit_point(t_ray *ray, double t)
{
	t_vec	*hitp;

	hitp = vector_scalar_multiply(ray->d, t);
	hitp = vectorx(hitp, vector_sum(hitp, ray->a));
	return (hitp);
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
	if (hit_inside_sphere(hit->ray, hit->primitive) && \
		vector_vector_distance(hit->primitive->o, l) >
		hit->primitive->h)
		return (ray_destroy_and_return(ray, 0.0));
	return (ray_destroy_and_return(ray, 1.0));
}

t_hit	*hit_new(double max)
{
	t_hit	*hit;

	hit = ft_calloc(sizeof(t_hit), 1);
	hit->t = max;
	return (hit);
}
