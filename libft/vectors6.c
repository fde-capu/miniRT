/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:06:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 15:31:06 by fde-capu         ###   ########.fr       */
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

t_vec	*vector_subtract(t_vec *a, t_vec *b)
{
	t_vec	*sub;

	sub = vector_scalar_multiply(b, -1);
	sub = vectorx(sub, vector_sum(a, sub));
	return (sub);
}

t_vec	*vector_scalar_multiply(t_vec *a, double scalar)
{
	t_dbl	*h;
	t_vec	*out;

	out = vector_copy(a);
	h = out->i;
	while (h)
	{
		h->d *= scalar;
		h = h->nx;
	}
	return (out);
}

t_vec	*vector_copy(t_vec *a)
{
	t_vec	*c;
	t_dbl	*h;

	c = vector_new();
	c->m = a->m;
	c->n = a->n;
	h = a->i;
	while (h)
	{
		c->i = lstdbl_addlast(c->i, h->d);
		h = h->nx;
	}
	return (c);
}
