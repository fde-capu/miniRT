/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:31:17 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/29 15:33:15 by fde-capu         ###   ########.fr       */
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

t_vec	*vector_scalar_sum(t_vec *vec, double val)
{
	t_dbl	*h;
	t_vec	*out;

	out = vector_copy(vec);
	h = out->i;
	while (h)
	{
		h->d += val;
		h = h->nx;
	}
	return (out);
}

t_vec	*vector_normal_construct(t_vec *ori, t_vec *dest)
{
	t_vec	*vec;

	vec = vector_subtract(dest, ori);
	vector_normalize(vec);
	return (vec);
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
