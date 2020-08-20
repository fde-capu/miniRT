/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:01:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 09:09:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** vector_cross_product
** Only R = 3 (3D) allowed.
** Using right hand.
*/

t_vec	*vector_cross_product(t_vec *x, t_vec *y)
{
	t_vec	*cpd;

	if ((x->m != 3 || y->m != 3)
		|| (!(vector_magnitude(x) || !(vector_magnitude(y)))))
		ft_die(CROSSPRODERR, ERRCROSSPROD);
	if (vector_vector_angle_deg(x, y) == 180.0 || vector_vector_angle_deg(x, y) == 0.0)
		return (vector_empty(3));
	cpd = vector_new();
	cpd->n = 1;
	cpd->m = 3;
	cpd->i = lstdbl_addlast(cpd->i, \
		(vector_get_element(x, 2) * vector_get_element(y, 3)) \
		- (vector_get_element(y, 2) * vector_get_element(x, 3)));
	cpd->i = lstdbl_addlast(cpd->i, \
		(vector_get_element(x, 3) * vector_get_element(y, 1)) \
		- (vector_get_element(y, 3) * vector_get_element(x, 1)));
	cpd->i = lstdbl_addlast(cpd->i, \
		(vector_get_element(x, 1) * vector_get_element(y, 2)) \
		- (vector_get_element(y, 1) * vector_get_element(x, 2)));
	return (cpd);
}

double	vector_vector_angle_rad(t_vec *x, t_vec *y)
{
	double	cos;

	cos = vector_dot_product(x, y) / (vector_magnitude(x) * vector_magnitude(y));
	return (acos(cos));
}

int		vector_parallel(t_vec *x, t_vec *y)
{
	double	deg;

	deg = vector_vector_angle_deg(x, y);
	return (deg == 180.0 || deg == 0 ? 1 : 0);
}

double	vector_vector_angle_deg(t_vec *x, t_vec *y)
{
	return (radtodeg(vector_vector_angle_rad(x, y)));
}

/*
**  vector_magnitude ::
**	dp *= dp <= 0 ? -1 : 1; // Feels weird, isn't it always positive?
*/

double	vector_magnitude(t_vec *v)
{
	double	dp;

	dp = vector_dot_product(v, v);
	dp = (double)sqrt(dp);
	dp *= dp <= 0 ? -1 : 1;
	return (dp);
}

double	vector_pop(t_vec *vec)
{
	double	d;

	d = lstdbl_pop(vec->i);
	vec->m--;
	if (!vec->m)
		vec->i = 0;
	return (d);
}

void	vector_append_val(t_vec *vec, double val)
{
	vec->i = lstdbl_addlast(vec->i, val);
	vec->m++;
	return ;
}

t_vec	*vector_translate(t_vec *vec, t_vec *xyz)
{
	t_mat	*map;
	t_vec	*translated;

	map = matrix_identity(xyz->m + 1);
	matrix_put_matrix(map, (t_mat *)xyz, 1, xyz->m + 1);
	vector_append_val(vec, 1);
	translated = matrix_vector_multiply(map, vec);
	matrix_destroy(map);
	vector_pop(translated);
	return (translated);
}

void	vector_multiply_element(t_vec *vec, int elem, double factor)
{
	vector_put_element(vec, elem, vector_get_element(vec, elem) * factor);
	return ;
}
