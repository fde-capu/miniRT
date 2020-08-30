/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:16:55 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/30 01:45:08 by fde-capu         ###   ########.fr       */
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
