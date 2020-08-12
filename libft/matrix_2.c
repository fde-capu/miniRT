/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:59:52 by fde-capu          #+#    #+#             */
/*   Updated: 2020/08/12 11:19:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mat	*matrix_subtract(t_mat *a, t_mat *b)
{
	t_mat	*subtracted;
	t_mat	*temp;

	temp = matrix_scalar_multiply(b, -1.0);
	subtracted = matrix_sum(a, temp);
	matrix_destroy(temp);
	return (subtracted);
}

t_mat	*matrix_matrix_multiply(t_mat *a, t_mat *b)
{
	t_mat	*c;
	t_vec	*v;
	t_vec	*v2;
	int		j;
	int		i;

	if (b->m != a->n)
		return (0);
	v = vector_new();
	v2 = vector_new();
	c = matrix_empty(a->m, b->n);
	j = 1;
	while (j <= b->n)
	{
		v = vectorx(v, matrix_get_vector(b, j));
		i = 1;
		while (i <= a->m)
		{
			v2 = vectorx(v2, matrix_get_line_transposed(a, i));
			matrix_put_element(c, i, j, vector_dot_product(v, v2));
			i++;
		}
		j++;
	}
	vector_destroy(v);
	return (c);
}

t_vec	*matrix_vector_multiply(t_mat *left, t_vec *right)
{
	return ((t_vec *)matrix_matrix_multiply(left, (t_mat *)right));
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
	madj = matrixx(madj, matrix_of_cofactors(madj));
	madj = matrixx(madj, matrix_transpose(madj));
	return (madj);
}
