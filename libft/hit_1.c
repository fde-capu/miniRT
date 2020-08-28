/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:11:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 04:51:41 by fde-capu         ###   ########.fr       */
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
	double	discriminant;

	oc = vector_subtract(ray->a, sphere->o);
	a = 1.0;
	b = 2.0 * vector_dot_product(oc, ray->d);
	c = vector_dot_product(oc, oc) - (sphere->h * sphere->h);
	discriminant = (b * b) - (4.0 * a * c);
	vector_destroy(oc);
	if (discriminant < 0)
		return (0.0);
	else
	{
		c = (-b - sqrt(discriminant)) / (2.0 * a);
		if (c > 0)
			return (hit_minimal(c));
		return (hit_minimal((-b + sqrt(discriminant)) / (2.0 * a)));
	}
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

int		inside_cylinder_bondaries(t_ray *ray, double t, t_prm *cylinder)
{
	double	d;
	int		is_it;
	t_vec	*hp;
	t_vec	*hpm;

	is_it = 1;
	hp = hit_point(ray, t);
	hpm = vector_subtract(hp, cylinder->o);
	d = vector_dot_product(hpm, cylinder->n);
	if ((d > cylinder->h) || (d < 0))
		is_it = 0;
	vector_destroy(hpm);
	vector_destroy(hp);
	return (is_it);
}
