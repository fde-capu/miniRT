/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:59:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/01 15:59:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_subtract(t_mat *a, t_mat *b)
{
	t_mat	*subtracted;
	t_mat	*temp;

	temp = matrix_multiply_scalar(b, -1);
	subtracted = matrix_sum(a, temp);
	matrix_destroy(temp);
	return (subtracted);
}

t_mat	*matrix_matrix_multiply(t_mat *a, t_mat *b)
{
	t_mat	*c;
	t_vec	*v;
	int		j;

	if (b->m != a->n)
		return (0);
	v = vector_new();
	c = matrix_empty(a->m, b->n);
	j = 1;
	while (j <= b->n)
	{
		v = vectorx(v, matrix_get_vector(b, j));
		v = vectorx(v, matrix_vector_multiply(a, v));
		matrix_put_matrix(c, (t_mat *)v, 1, j);
		j++;
	}
	vector_destroy(v);
	return (c);
}

t_vec	*matrix_vector_multiply(t_mat *left, t_vec *right)
{
	t_vec	*vec;
	int		i;
	int		j;
	double	d;

	vec = vector_new();
	i = 1;
	while (i <= left->m)
	{
		d = 0;
		j = 1;
		while (j <= right->m)
		{
			d += (vector_get_element(right, j)
				* matrix_get_element(left, i, j));
			j++;
		}
		vec->i = lstdbl_addlast(vec->i, d);
		i++;
	}
	vec->m = right->m;
	vec->n = right->n;
	return (vec);
}

double	matrix_determinant(t_mat *a)
{
	double	mult;
	int		c;
	double	det;
	t_mat	*temp;

	if (a->m != a->n)
		return (0);
	if (a->n == 1)
		return (a->i->d);
	temp = matrix_new();
	c = 1;
	mult = 1;
	det = 0;
	while (c <= a->n)
	{
		temp = matrixx(temp, matrix_minor(a, 1, c));
		det += mult * (matrix_get_element(a, 1, c) \
			* matrix_determinant(temp));
		c++;
		mult *= -1;
	}
	matrix_destroy(temp);
	return (det);
}

t_mat	*matrix_adjoint(t_mat *m)
{
	t_mat	*madj;

	madj = matrix_of_minors(m);
	madj = ft_x(madj, matrix_of_cofactors(madj));
	madj = ft_x(madj, matrix_transpose(madj));
	return (madj);
}
