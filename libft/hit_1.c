/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 17:24:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	hit_minimal(double t)
{
	return (t > EPSILON ? t : 0.0);
}

double	hit_sphere(t_ray *ray, t_prm *sphere)
{
	t_vec	*oc;
	double	a;
	double	b;
	double	c;
	double	t;

	oc = vector_subtract(ray->a, sphere->o);
	a = 1.0;
	b = 2.0 * vector_dot_product(oc, ray->d);
	c = vector_dot_product(oc, oc) - (sphere->h * sphere->h);
	vector_destroy(oc);
	if (hit_inside_sphere(ray, sphere))
		t = quadratic_major(a, b, c);
	else
		t = quadratic_minor(a, b, c);
	return (hit_minimal(t));
}

double	hit_plane(t_ray *ray, t_prm *plane)
{
	t_vec	*vec;
	double	t;
	double	t2;

	vec = vector_subtract(plane->o, ray->a);
	t = vector_dot_product(vec, plane->n);
	vector_destroy(vec);
	t2 = vector_dot_product(ray->d, plane->n);
	if (t2 == 0)
		return (0.0);
	return (hit_minimal(t / t2));
}

double	hit_disc(t_ray *ray, t_prm *disc)
{
	double	t;
	t_vec	*vec;

	t = hit_plane(ray, disc);
	vec = hit_point(ray, t);
	vec = vectorx(vec, vector_subtract(vec, disc->o));
	if (vector_magnitude(vec) <= disc->h)
	{
		vector_destroy(vec);
		return (hit_minimal(t));
	}
	vector_destroy(vec);
	return (0.0);
}

void	destroy_hit_triangle(t_vec *hit, t_vec *pos[3], t_prm *pl, t_vec *v)
{
	vector_destroy(hit);
	free(pl);
	vector_destroy(v);
	vector_destroy(pos[0]);
	vector_destroy(pos[1]);
	vector_destroy(pos[2]);
	return ;
}
