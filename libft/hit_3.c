/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:35:36 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 01:21:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	intersect_normal(t_hit *hit)
{
	t_vec	*vec;
	double	d;

	if (hit->primitive)
	{
		if (hit->primitive->type == TYPE_SP)
		{
			hit->n = vector_normal_construct(hit->primitive->o, hit->phit);
			return ;
		}
		if (hit->primitive->type == TYPE_CY)
		{
			vec = vector_subtract(hit->phit, hit->primitive->o);
			d = vector_dot_product(hit->primitive->n, vec);
			vec = vectorx(vec, vector_scalar_multiply(hit->primitive->n, d));
			vec = vectorx(vec, vector_sum(vec, hit->primitive->o));
			hit->n = vector_normal_construct(vec, hit->phit);
			vector_destroy(vec);
			return ;
		}
		hit->n = intersect_normal_generic_primitive(hit);
		return ;
	}
	hit->n = intersect_normal_triangle(hit);
	return ;
}

t_vec	*intersect_normal_generic_primitive(t_hit *hit)
{
	t_vec	*norm;

	if (vector_dot_product(hit->ray->d, hit->primitive->n) < 0.0)
		norm = vector_copy(hit->primitive->n);
	else
		norm = vector_scalar_multiply(hit->primitive->n, -1.0);
	return (norm);
}

t_vec	*intersect_normal_triangle(t_hit *hit)
{
	t_vec	*norm;

	if (vector_dot_product(hit->ray->d, hit->triangle->n) < 0.0)
		norm = vector_copy(hit->triangle->n);
	else
		norm = vector_scalar_multiply(hit->triangle->n, -1.0);
	return (norm);
}

void	hit_set_primitive(t_hit *hit, double test, t_prm *primitive, t_ray *ray)
{
	hit->t = test;
	hit->primitive = primitive;
	hit->triangle = 0;
	hit->ray = ray;
	return ;
}

void	hit_set_triangle(t_hit *hit, double test, t_tri *triangle, t_ray *ray)
{
	hit->t = test;
	hit->triangle = triangle;
	hit->primitive = 0;
	hit->ray = ray;
}
