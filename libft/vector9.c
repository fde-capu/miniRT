/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:19:12 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/27 17:31:57 by fde-capu         ###   ########.fr       */
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
