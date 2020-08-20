/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:23:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 17:51:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ray	*ray_build(t_vec *a, t_vec *point_b)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->a = vector_copy(a);
	ray->point_a = ray->a;
	ray->o = ray->a;
	ray->b = vector_subtract(point_b, a);
	vector_normalize(ray->b);
	ray->d = ray->b;
	return (ray);
}

void	ray_destroy(t_ray *ray)
{
	vector_destroy(ray->a);
	vector_destroy(ray->b);
	vector_destroy(ray->point_b);
	return (free(ray));
}

int		hit_sphere(t_ray *ray, t_prm *sphere)
{
	t_vec	*oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vector_subtract(ray->o, sphere->o);
	a = vector_dot_product(ray->d, ray->d);
	b = 2.0 * vector_dot_product(oc, ray->d);
	c = vector_dot_product(oc, oc) - (sphere->h * sphere->h);
	discriminant = (b * b) - (4 * a * c);
	vector_destroy(oc);
	return (discriminant > 0 ? 1 : 0);
}