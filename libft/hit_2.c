/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:09:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 15:22:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*triangle_normal(t_tri *tri)
{
	t_vec	*tri_hat[3];
	t_vec	*plane_n;

	tri_hat[0] = vector_subtract(tri->b, tri->a);
	tri_hat[1] = vector_subtract(tri->c, tri->b);
	tri_hat[2] = vector_subtract(tri->a, tri->c);
	plane_n = vector_cross_product(tri_hat[0], tri_hat[1]);
	vector_destroy(tri_hat[0]);
	vector_destroy(tri_hat[1]);
	vector_destroy(tri_hat[2]);
	return (plane_n);
}

t_vec	*hit_triangle_crosshit(t_vec *hit, t_vec *tri_a, t_vec *tri_b)
{
	t_vec	*tri;
	t_vec	*pos;

	tri = vector_subtract(tri_a, tri_b);
	pos = vector_subtract(hit, tri_b);
	pos = vectorx(pos, vector_cross_product(tri, pos));
	vector_destroy(tri);
	return (pos);
}

double	hitcyldie(double val, t_ray *ray, t_prm *cyl)
{
	primitive_destroy(cyl);
	return (ray_destroy_and_return(ray, val));
}

//double	hit_cylinder0(t_ray *ray, t_prm *cyl)
//{
//	double	t;
//	return (t);
//}

double	hit_cylinder(t_ray *ray3d, t_prm *cylinder)
{
	double	t1;
	double	t2;
	t_prm	*cyl;
	t_ray	*ray;
	double	abc[3];

	cyl = cylinder_init(vector_copy(cylinder->o), \
		vector_copy(cylinder->n), cylinder->d, cylinder->h);
	ray = ray_copy(ray3d);
	primitive_zzz_position(cyl, ray);
	abc[0] = cyl->d;
	quadratic_build(ray, &abc[0], &abc[1], &abc[2]);
	t1 = quadratic_minor(abc[0], abc[1], abc[2]);
	t2 = quadratic_major(abc[0], abc[1], abc[2]);
	t1 = inside_cylinder_bondaries(ray3d, t1, cylinder) ? t1 : 0.0;
	t2 = inside_cylinder_bondaries(ray3d, t2, cylinder) ? t2 : 0.0;
	t1 = t1 > EPSILON ? t1 : 0.0;
	t2 = t2 > EPSILON ? t2 : 0.0;
	primitive_destroy(cyl);
	ray_destroy(ray);
	return (hit_minimal(t1 ? t1 : t2));
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
	if ((d < 0.0) || (d > cylinder->h))
		is_it = 0;
	vector_destroy(hpm);
	vector_destroy(hp);
	return (is_it);
}
