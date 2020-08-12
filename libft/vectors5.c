/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:01:37 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/11 12:15:57 by fde-capu         ###   ########.fr       */
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

	if (x->m != 3 || y->m != 3)
		ft_die(CROSSPRODERR, ERRCROSSPROD);
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
