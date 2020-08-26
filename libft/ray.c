/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:23:59 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/26 00:34:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ray	*ray_build(t_vec *a, t_vec *point_b)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->a = vector_copy(a);
	ray->b = vector_copy(point_b);
	ray->d = vector_subtract(point_b, a);
	vector_normalize(ray->d);
	return (ray);
}

t_ray	*ray_copy(t_ray *src)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->a = vector_copy(src->a);
	ray->b = vector_copy(src->b);
	ray->d = vector_copy(src->d);
	return (ray);
}

void	ray_transform(t_ray *ray, t_mat *trn)
{
	vector_transform(&(ray->a), trn);
	vector_transform(&(ray->b), trn);
	vector_transform(&(ray->d), trn);
	return ;
}

void	ray_translate(t_ray *ray, t_vec *trn)
{
	ray->a = vectorx(ray->a, vector_translate(ray->a, trn));
	ray->b = vectorx(ray->b, vector_translate(ray->b, trn));
	ray->d = vectorx(ray->d, vector_translate(ray->d, trn));
	return ;
}

void	vector_smash_z(t_vec *vec)
{
	vector_put_element(vec, 3, 0.0);
	return ;
}

void	ray_smash_z(t_ray *ray)
{
	vector_put_element(ray->a, 3, 0.0);
	vector_put_element(ray->b, 3, 0.0);
	vector_put_element(ray->d, 3, 0.0);
	vector_normalize(ray->d);
	return ;
}

void	ray_destroy(t_ray *ray)
{
	vector_destroy(ray->a);
	vector_destroy(ray->b);
	vector_destroy(ray->d);
	return (free(ray));
}

void	ray_verb(char *str, t_ray *ray)
{
	DEB(str);
	DEBVEC("a", ray->a);
	DEBVEC("b", ray->b);
	DEBVEC("d", ray->d);
	return ;
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

	oc = vector_subtract(ray->a, sphere->o);
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

void	primitive_transform(t_prm *prm, t_mat *trm)
{
	if (prm->o)
		vector_transform(&prm->o, trm);
	if (prm->n)
		vector_transform(&prm->n, trm);
	return ;
}

void	triangle_transform(t_tri *tri, t_mat *trm)
{
	if (tri->a)
		vector_transform(&tri->a, trm);
	if (tri->b)
		vector_transform(&tri->b, trm);
	if (tri->c)
		vector_transform(&tri->c, trm);
	if (tri->n)
		vector_transform(&tri->n, trm);
	return ;
}

void	primitive_translate(t_prm *prm, t_mat *trm)
{
	if (prm->o)
		prm->o = vectorx(prm->o, vector_translate(prm->o, trm));
	if (prm->n)
		prm->n = vectorx(prm->n, vector_translate(prm->n, trm));
	return ;
}

void	triangle_translate(t_tri *tri, t_mat *trm)
{
	if (tri->a)
		tri->a = vectorx(tri->a, vector_translate(tri->a, trm));
	if (tri->b)
		tri->b = vectorx(tri->b, vector_translate(tri->b, trm));
	if (tri->c)
		tri->c = vectorx(tri->c, vector_translate(tri->c, trm));
	if (tri->n)
		tri->n = vectorx(tri->n, vector_translate(tri->n, trm));
	return ;
}

double	quadratic_minor(double a, double b, double c)
{
	double	discriminant;

	discriminant = (b * b) - (4.0 * a * c);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}

void	primitive_zzz_position(t_prm *cyl, t_ray *ray)
{
	t_vec	*zzz;
	t_mat	*rot;

	rot = vector_vector_rotation_matrix(cyl->n, g_z);
	zzz = vector_scalar_multiply(cyl->o, -1.0);
	ray_translate(ray, zzz);
	ray_transform(ray, rot);
	primitive_translate(cyl, zzz);
	primitive_transform(cyl, rot);
	vector_destroy(zzz);
	matrix_destroy(rot);
	return ;
}

double	hit_infinite_cylinder(t_ray *ray3d, t_prm *cylinder)
{
	double	t;
	t_prm	*cyl;
	t_ray	*ray;
	double	dx;
	double	dy;
	double	x0;
	double	y0;
	double	a;
	double	b;
	double	c;

	ray = ray_copy(ray3d);
	cyl = cylinder_init(vector_copy(cylinder->o), vector_copy(cylinder->n), cylinder->h, cylinder->d);
	primitive_zzz_position(cyl, ray);
	dx = vector_get_element(ray->d, 1);
	dy = vector_get_element(ray->d, 2);
	x0 = vector_get_element(ray->a, 1);
	y0 = vector_get_element(ray->a, 2);
	a = ((dx * dx) + (dy * dy));
	b = ((x0 * dx) + (y0 * dy)) * 2;
	c = ((x0 * x0) + (y0 * y0)) - ((cyl->h / 2) * (cyl->h / 2));
	t = quadratic_minor(a, b, c);
	ray_destroy(ray);
	primitive_destroy(cyl);
	return (t);
}

double	hit_cylinder(t_ray *ray, t_prm *cylinder)
{
	double	t;
	t_vec	*hp;
	double	d;
	t_vec	*hpm;

	t = hit_infinite_cylinder(ray, cylinder);
	hp = hit_point(ray, t);
	hpm = vector_subtract(hp, cylinder->o);
	d = vector_dot_product(hpm, cylinder->n);
	if ((d > cylinder->h) || (d < 0))
		t = 0.0;
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

double	hit_triangle_helper(t_ray *ray, t_vec *a, t_vec *b, t_vec *c)
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

double	hit_triangle(t_ray *ray, t_tri *tri)
{
	return (hit_triangle_helper(ray, tri->a, tri->b, tri->c));
}

double	hit_square(t_ray *ray, t_prm *square)
{
	t_vec	*p[4];
	t_mat	*rot;
	double	t;
	t_tri	*tri[2];

	p[0] = vector_build(3, -square->h / 2.0, square->h / 2.0, 0.0);
	p[1] = vector_build(3, square->h / 2.0, square->h / 2.0, 0.0);
	p[2] = vector_build(3, square->h / 2.0, -square->h / 2.0, 0.0);
	p[3] = vector_build(3, -square->h / 2.0, -square->h / 2.0, 0.0);
	tri[0] = triangle_init(vector_copy(p[2]), vector_copy(p[1]), vector_copy(p[0]), square->rgb);
	tri[1] = triangle_init(vector_copy(p[0]), vector_copy(p[3]), vector_copy(p[2]), square->rgb);
	rot = vector_vector_rotation_matrix(g_z, square->n);
	triangle_transform(tri[0], rot);
	triangle_transform(tri[1], rot);
	triangle_translate(tri[0], square->o);
	triangle_translate(tri[1], square->o);
	t = hit_triangle(ray, tri[0]);
	t = t ? t : hit_triangle(ray, tri[1]);
	vector_destroy(p[0]);
	vector_destroy(p[1]);
	vector_destroy(p[2]);
	vector_destroy(p[3]);
	matrix_destroy(rot);
	triangle_destroy(tri[0]);
	triangle_destroy(tri[1]);
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
