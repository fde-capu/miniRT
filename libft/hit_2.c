/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:09:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/28 04:58:35 by fde-capu         ###   ########.fr       */
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

void	intersect_phit(t_hit *hit)
{
	hit->phit = hit_point(hit->ray, hit->t);
	return ;
}

double	hit_cylinder(t_ray *ray3d, t_prm *cylinder)
{
	double	t;
	t_prm	*cyl;
	t_ray	*ray;
	double	abc[3];

	cyl = cylinder_init(vector_copy(cylinder->o), \
		vector_copy(cylinder->n), cylinder->h, cylinder->d);
	abc[0] = cyl->h / 2;
	ray = ray_quadratic(ray3d, &abc[0], &abc[1], &abc[2]);
	primitive_zzz_position(cyl, ray);
	t = quadratic_minor(abc[0], abc[1], abc[2]);
	if (!inside_cylinder_bondaries(ray3d, t, cylinder))
	{
		t = quadratic_major(abc[0], abc[1], abc[2]);
		if (!inside_cylinder_bondaries(ray3d, t, cylinder))
			t = 0.0;
	}
	ray_destroy(ray);
	primitive_destroy(cyl);
	return (hit_minimal(t));
}
