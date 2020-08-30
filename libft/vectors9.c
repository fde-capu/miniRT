/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:58:11 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 17:53:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*vector_vector_rotation_matrix(t_vec *v1, t_vec *v2)
{
	double	theta;
	t_vec	*axis;
	t_mat	*rvv;

	theta = vector_vector_angle_rad(v1, v2);
	axis = vector_cross_product(v1, v2);
	rvv = axis_angle_rotation(axis, theta);
	vector_destroy(axis);
	return (rvv);
}

double	vector_vector_distance(t_vec *a, t_vec *b)
{
	t_vec	*tmp;
	double	mag;

	tmp = vector_subtract(b, a);
	mag = vector_magnitude(tmp);
	vector_destroy(tmp);
	return (mag);
}

t_vec	*vector_origin_scale(t_vec *a, t_vec *o, double factor)
{
	t_vec	*scaled;

	scaled = vector_inverse_translate(a, o);
	scaled = vectorx(scaled, vector_scalar_multiply(scaled, factor));
	scaled = vectorx(scaled, vector_translate(scaled, o));
	return (scaled);
}

t_vec	*vector_inverse_translate(t_vec *vec, t_vec *trans)
{
	t_vec	*inv;
	t_vec	*copy;

	copy = vector_copy(vec);
	inv = vector_scalar_multiply(trans, -1.0);
	copy = vectorx(copy, vector_translate(copy, inv));
	vector_destroy(inv);
	return (copy);
}

t_vec	*vector_halfway(t_vec *a, t_vec *b)
{
	t_vec	*half;

	half = vector_subtract(b, a);
	half = vectorx(half, vector_scalar_multiply(half, 0.5));
	half = vectorx(half, vector_sum(half, a));
	return (half);
}
