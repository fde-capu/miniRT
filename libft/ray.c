/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:23:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/24 19:04:09 by fde-capu         ###   ########.fr       */
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

/*
**	a = vector_dot_product(ray->d, ray->d);
*/

double	hit_sphere(t_ray *ray, t_prm *sphere)
{
	t_vec	*oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vector_subtract(ray->o, sphere->o);
	a = 1.0;
	b = 2.0 * vector_dot_product(oc, ray->d);
	c = vector_dot_product(oc, oc) - (sphere->h * sphere->h);
	discriminant = (b * b) - (4.0 * a * c);
	vector_destroy(oc);
	if (discriminant < 0)
		return (-1.0);
	else
		return (hit_minimal((-b - sqrt(discriminant)) / (2.0 * a)));
}

double	hit_plane(t_ray *ray, t_prm *plane)
{
	t_vec	*vec;
	double	t;
	double	t2;

	vec = vector_subtract(plane->o, ray->o);
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

double	hit_triangle(t_ray *ray, t_vec *a, t_vec *b, t_vec *c)
{
	t_prm	*plane;
	t_vec	*plane_n;
	t_vec	*tri[3];
	t_vec	*pos[3];
	double	t;
	t_vec	*hit;

	tri[0] = vector_subtract(b, a);
	tri[1] = vector_subtract(c, b);
	tri[2] = vector_subtract(a, c);
	plane_n = vector_cross_product(tri[0], tri[1]);
	plane = plane_init(a, plane_n, ft_rgb(0.0, 0.0, 0.0, 0.0));
	t = hit_plane(ray, plane);
	hit = hit_point(ray, t);
	pos[0] = vector_subtract(hit, a);
	pos[1] = vector_subtract(hit, b);
	pos[2] = vector_subtract(hit, c);
	pos[0] = vectorx(pos[0], vector_cross_product(tri[0], pos[0]));
	pos[1] = vectorx(pos[1], vector_cross_product(tri[1], pos[1]));
	pos[2] = vectorx(pos[2], vector_cross_product(tri[2], pos[2]));
	if ((vector_dot_product(plane_n, pos[0]) <= 0.0)
		|| (vector_dot_product(plane_n, pos[1]) <= 0.0)
		|| (vector_dot_product(plane_n, pos[2]) <= 0.0))
		t = 0.0;
	free(plane);
	vector_destroy(plane_n);
	vector_destroy(pos[0]);
	vector_destroy(pos[1]);
	vector_destroy(pos[2]);
	vector_destroy(tri[0]);
	vector_destroy(tri[1]);
	vector_destroy(tri[2]);
	vector_destroy(hit);
	return (hit_minimal(t));
}

double	hit_square(t_ray *ray, t_prm *square)
{
	t_vec	*p[5];
	t_mat	*rot;
	double	t;

	t = 0.0;
	p[0] = vector_copy(g_z);
	p[1] = vector_build(3, -square->h / 2, square->h / 2, 0.0);
	p[2] = vector_build(3, square->h / 2, square->h / 2, 0.0);
	p[3] = vector_build(3, square->h / 2, -square->h / 2, 0.0);
	p[4] = vector_build(3, -square->h / 2, -square->h / 2, 0.0);
	rot = vector_vector_rotation_matrix(p[0], square->n);
	vector_transform(&p[1], rot);
	vector_transform(&p[2], rot);
	vector_transform(&p[3], rot);
	vector_transform(&p[4], rot);
	p[1] = vectorx(p[1], vector_translate(p[1], square->o));
	p[2] = vectorx(p[2], vector_translate(p[2], square->o));
	p[3] = vectorx(p[3], vector_translate(p[3], square->o));
	p[4] = vectorx(p[4], vector_translate(p[4], square->o));
	if ((hit_triangle(ray, p[3], p[2], p[1])
		|| hit_triangle(ray, p[1], p[4], p[3])))
		t = hit_plane(ray, square);
	vector_destroy(p[0]);
	vector_destroy(p[1]);
	vector_destroy(p[2]);
	vector_destroy(p[3]);
	vector_destroy(p[4]);
	matrix_destroy(rot);
	return (hit_minimal(t));
}

double	hit_minimal(double t)
{
	return (t > 0.01 ? t : 0.0);
}

void	missing_up_gambiarra(t_vec *p, t_vec **v_up, t_vec **v_left)
{
	if (vector_parallel(p, g_z))
	{
		*v_left = vector_copy(g_x);
		*v_up = vector_cross_product(*v_left, p);
	}
	else
	{
		*v_left = vector_cross_product(g_z, p);
		*v_up = vector_cross_product(p, *v_left);
	}
	*v_left = vectorx(*v_left, vector_cross_product(*v_up, p));
	return ;
}
