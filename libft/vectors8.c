/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:31:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 19:02:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*vector_translate(t_vec *vec, t_vec *xyz)
{
	t_mat	*map;
	t_vec	*translated;

	map = matrix_identity(xyz->m + 1);
	matrix_put_matrix(map, (t_mat *)xyz, 1, xyz->m + 1);
	vector_append_val(vec, 1.0);
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
