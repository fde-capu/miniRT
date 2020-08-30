/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:44:29 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 01:57:07 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	can_see_light(t_mrt *mrt, t_hit *hit, t_vec *l)
{
	double	test;

	test = can_see_light_primitive(mrt, hit, l);
	if (!test)
		return (test);
	test = can_see_light_triangle(mrt, hit, l);
	if (!test)
		return (test);
	return (1.0);
}

double	can_see_light_primitive(t_mrt *mrt, t_hit *hit, t_vec *l)
{
	double	test;
	t_prm	*primitive;
	t_ray	*ray;
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
	if (hit->primitive && hit->primitive->type == TYPE_SP && \
		hit_inside_sphere(hit->ray, hit->primitive) && \
		vector_vector_distance(hit->primitive->o, l) > hit->primitive->h)
		return (ray_destroy_and_return(ray, 0.0));
	return (ray_destroy_and_return(ray, 1.0));
}

double	can_see_light_triangle(t_mrt *mrt, t_hit *hit, t_vec *l)
{
	double	test;
	t_ray	*ray;
	t_tri	*tri;
	double	light_distance;

	ray = ray_build(hit->phit, l);
	light_distance = vector_vector_distance(hit->phit, l);
	tri = mrt->scn->faces;
	while (tri)
	{
		test = hit_triangle(ray, tri);
		if (test && test <= light_distance)
			return (ray_destroy_and_return(ray, 0.0));
		tri = tri->nx;
	}
	return (ray_destroy_and_return(ray, 1.0));
}
