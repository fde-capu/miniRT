/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:06:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/07 15:35:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*vector_scale(t_vec *vec, t_vec *xyz)
{
	t_mat	*map;
	t_vec	*scaled;

	vector_append_val(xyz, 1);
	map = matrix_diagonal(xyz);
	scaled = matrix_vector_multiply(map, vec);
	vector_pop(scaled);
	matrix_destroy(map);
	vector_destroy(xyz);
	return (scaled);
}

t_vec	*vector_sum(t_vec *a, t_vec *b)
{
	return ((t_vec *)matrix_sum((t_mat *)a, (t_mat *)b));
}
