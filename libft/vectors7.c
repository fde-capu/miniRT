/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:30:29 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/20 15:31:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*vector_matrix_multiply(t_vec *left, t_mat *right)
{
	t_mat	*foo_transpose;
	t_mat	*ret;

	foo_transpose = vector_transpose(left);
	ret = matrix_matrix_multiply(foo_transpose, right);
	ret = matrixx(ret, matrix_transpose(ret));
	matrix_destroy(foo_transpose);
	return (ret);
}

void	vector_transform(t_vec **vec, t_mat *trans)
{
	*vec = vectorx(*vec, vector_matrix_multiply(*vec, trans));
	return ;
}

int		vector_equal(t_vec *a, t_vec *b)
{
	t_dbl	*ha;
	t_dbl	*hb;

	if (a->m != b->m || a->n != b->n)
		return (0);
	ha = a->i;
	hb = b->i;
	while (ha)
	{
		if (ha->d != hb->d)
			return (0);
		ha = ha->nx;
		hb = hb->nx;
	}
	return (1);
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
